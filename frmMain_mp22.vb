Imports PcaConnect
Imports mvc
Imports nx30p6903_mp22_fields

Public Class frmMain_mp22

    Private Enum ViewEnum
        ve_Functional
        ve_RegisterMap
    End Enum

    Private Const WM_DEVICECHANGE As Integer = &H219
    Private Const DBT_DEVICEARRIVAL As Integer = &H8000
    Private Const DBT_DEVICEREMOVECOMPLETE As Integer = &H8004
    Private Const cDelayAfterUSBEnum_ms As Int64 = 500
    Private Const cAardvark_ID As UInt32 = 2
    Private Const cFT232_ID As UInt32 = 5

#If DEBUG Then
    'Private Const cSlaBase As Byte = &H34
    Private Const cSlaBase As Byte = &H36
#Else
    Private Const cSlaBase As Byte = &H36
#End If

    Private m_scheduleScan As Int64 = 0
    Private m_scheduleConnect As Int64 = 0
    Private m_scheduleStatusRead As Int64 = 0
    Private m_I2Cconnected As Boolean = False
    Private m_USBconnected As Boolean = False
    Private m_statusReadInterval As Int64   'Status registers read interval in ms

    Private Sub ScheduleStatusRead()
        If m_statusReadInterval > 0 Then
            m_scheduleStatusRead = TimeTicks() + m_statusReadInterval
        Else
            m_scheduleStatusRead = 0
        End If
    End Sub

    Private Sub UpdateModel()
        If Model.ReadAll() <> Model.pca_result_t.pca_ok Then I2C_connected = False
    End Sub

    Private Sub AttachModel()
        'v = New tea_mvc.View(txtVLoopTrim, Tea190x_fields.tea_data_fields_enum_t.v_loop_trim)
        'lblBGtrim.Text = Model.Caption(Tea190x_fields.tea_data_fields_enum_t.bandgap_trim)
        Dim v As New View(lblId, pca_data_fields_enum_t.dev_id)
        v = New View(lblRev, pca_data_fields_enum_t.dev_rev)
        v = New View(chkVoutEn, pca_data_fields_enum_t.vout_en)
        v = New View(lblVoutEn, pca_data_fields_enum_t.vout_en)
        v = New View(chkDetectEn, pca_data_fields_enum_t.detc_en)
        v = New View(lblDetectEn, pca_data_fields_enum_t.detc_en)
        v = New View(chkPwrOnSts, pca_data_fields_enum_t.pwron_sts)
        v = New View(chkTimeOutSts, pca_data_fields_enum_t.tmrout_sts)
        v = New View(chkSwitchOnSts, pca_data_fields_enum_t.swon_sts)
        v = New View(chkOverTagSts, pca_data_fields_enum_t.overtag_sts)
        v = New View(chkOVflag, pca_data_fields_enum_t.ov_flg)
        v = New View(chkOCflag, pca_data_fields_enum_t.oc_flg)
        v = New View(chkOTflag, pca_data_fields_enum_t.ot_flg)
        v = New View(chkPwrOnMask, pca_data_fields_enum_t.pwron_mask)
        v = New View(chkTimerOutMask, pca_data_fields_enum_t.tmrout_mask)
        v = New View(chkSwitchOnMask, pca_data_fields_enum_t.swon_mask)
        v = New View(chkOverTagMask, pca_data_fields_enum_t.overtag_mask)
        v = New View(chkOVMask, pca_data_fields_enum_t.ov_mask)
        v = New View(chkOCMask, pca_data_fields_enum_t.oc_mask)
        v = New View(chkOTMask, pca_data_fields_enum_t.ot_mask)
        lblOvloRng.Text = Model.Caption(pca_data_fields_enum_t.ovlo_rng)
        v = New View(cmbOvloRng, pca_data_fields_enum_t.ovlo_rng)
        lblOvloSel.Text = Model.Caption(pca_data_fields_enum_t.ovlo_sel)
        v = New View(cmbOvloSel, pca_data_fields_enum_t.ovlo_sel)
        lblOvloThres.Text = Model.Caption(pca_data_fields_enum_t.ovlo_ov)
        v = New View(cmbOvloThres, pca_data_fields_enum_t.ovlo_ov)
        lblIsrcReg.Text = Model.Caption(pca_data_fields_enum_t.isrc_val)
        v = New View(cmbIsrcVal, pca_data_fields_enum_t.isrc_val)
        lblIsrcDetReg.Text = Model.Caption(pca_data_fields_enum_t.isrc_det)
        v = New View(cmbIsrcDet, pca_data_fields_enum_t.isrc_det)
        lblVinDutyReg.Text = Model.Caption(pca_data_fields_enum_t.vin_duty)
        v = New View(cmbVinDuty, pca_data_fields_enum_t.vin_duty)
        lblVinTagReg.Text = Model.Caption(pca_data_fields_enum_t.tag_vin)
        v = New View(trbVinTagReg, pca_data_fields_enum_t.tag_vin)
        v = New View(lblVinTagRegVal, pca_data_fields_enum_t.tag_vin)
        lblVinAdc.Text = Model.Caption(pca_data_fields_enum_t.adc_vin)
        v = New View(txtVinAdc, pca_data_fields_enum_t.adc_vin)
        lblAVOP.Text = Model.Caption(pca_data_fields_enum_t.adt_ovp)
        v = New View(cmbAVOP, pca_data_fields_enum_t.adt_ovp)
        lblSRTune.Text = Model.Caption(pca_data_fields_enum_t.sr_tune)
        v = New View(cmbSRTune, pca_data_fields_enum_t.sr_tune)
    End Sub

    Private Property USB_connected As Boolean
        Get
            Return m_USBconnected
        End Get
        Set(value As Boolean)
            If value <> m_USBconnected Then
                m_USBconnected = value
                If value Then
                    tslInterface.Text = " [" & Connection.Info & "]"
                    I2C_Connect()
                Else
                    tslInterface.Text = " No hardware interface present"
                    I2C_connected = False
                End If
            End If
            If value = False Then m_scheduleScan = TimeTicks() + cDelayAfterUSBEnum_ms
        End Set
    End Property

    Private Sub I2C_Connect()
        If USB_connected Then
            Dim con As Boolean = False
            ' try all three addresses
            For idx As Integer = 0 To 2
                Model.SlaveAddress = CByte(cSlaBase + idx)
                con = mvc.Model.ReadRegister(0) = mvc.Model.pca_result_t.pca_ok
                If con Then
                    lblAddr.Text = "0x" & Hex(cSlaBase + idx)
                    Exit For
                End If
            Next
            I2C_connected = con
        End If
    End Sub

    Private Property I2C_connected As Boolean
        Get
            Return m_I2Cconnected
        End Get
        Set(value As Boolean)
            If value <> m_I2Cconnected Then
                If value Then
                    m_scheduleConnect = 0
                    tslConnection.Image = My.Resources.plug_connect
                    tslConnection.Text = "Connected"
                    UpdateModel()
                    ScheduleStatusRead()
                Else
                    m_scheduleStatusRead = 0
                    tslConnection.Image = My.Resources.plug_disconnect
                    tslConnection.Text = "Disconnected"
                End If
                m_I2Cconnected = value
            End If
            If m_I2Cconnected = False Then m_scheduleConnect = TimeTicks() + 250
        End Set
    End Property

    Private Sub ScanInterfaces()
        If Connection.SelectInterface(cAardvark_ID) <> Connection.pc_result_t.pc_ok Then
            Connection.SelectInterface(cFT232_ID)
        End If
        USB_connected = Connection.Connected
    End Sub

    Private Sub frmMain_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        'BeginInvoke(New MethodInvoker(AddressOf TestConnection))
        'ScanInterfaces()
        m_scheduleScan = TimeTicks() + 100
        tmrWork.Enabled = True
        AttachModel()
        AddInterruptChkHandlers()
        BuildRegisterMap()
        SetView(ViewEnum.ve_Functional)
        SetAutoRefresh(My.Settings.Interval)
    End Sub

    Protected Overrides Sub WndProc(ByRef m As System.Windows.Forms.Message)
        If m.Msg = WM_DEVICECHANGE Then
            If m.WParam.ToInt32 = DBT_DEVICEARRIVAL Or _
                m.WParam.ToInt32 = DBT_DEVICEREMOVECOMPLETE Or _
                 m.WParam.ToInt32 = 7 Then
                ' Scan for hardware interfaces after cDelayAfterUSBEnum_ms milisecond
                m_scheduleScan = TimeTicks() + cDelayAfterUSBEnum_ms
            End If
        End If
        MyBase.WndProc(m)
    End Sub

    Private Sub ReadStatusRegisters()
        'Beep()
        'Static cRegsToRead As Byte() = {3, 4, 19, 20, 21, 22, 23, 24, 25, 26, 27}
        'ScheduleStatusRead()
        'For idx As Integer = 0 To cRegsToRead.Count - 1
        '    If Model.ReadRegister(cRegsToRead(idx)) <> Model.pca_result_t.pca_ok Then
        '        I2C_connected = False
        '        Exit For
        '    End If
        'Next
        ScheduleStatusRead()
        'read 0x02 and 0x03
        If Model.ReadRegisters(2, 2) = Model.pca_result_t.pca_ok Then
            'read 0x08'
            If Model.ReadRegisters(8, 1) = Model.pca_result_t.pca_ok Then
                Exit Sub
            End If
        End If
        I2C_connected = False
    End Sub

    Private Sub tmrWork_Tick(sender As System.Object, e As System.EventArgs) Handles tmrWork.Tick
        If m_scheduleScan <> 0 AndAlso TimeTicks() - m_scheduleScan > 0 Then
            m_scheduleScan = 0
            BeginInvoke(New MethodInvoker(AddressOf ScanInterfaces))
        End If
        If m_scheduleConnect <> 0 AndAlso TimeTicks() - m_scheduleConnect > 0 Then
            m_scheduleConnect = 0
            BeginInvoke(New MethodInvoker(AddressOf I2C_Connect))
        End If
        If m_scheduleStatusRead <> 0 AndAlso TimeTicks() - m_scheduleStatusRead > 0 Then
            m_scheduleStatusRead = 0
            BeginInvoke(New MethodInvoker(AddressOf ReadStatusRegisters))
        End If
        'For Each chk As CheckBox In grpRaised.Controls.OfType(Of CheckBox)()
        '    Static tag As Integer
        '    tag = CInt(chk.Tag)
        '    If tag <> 0 Then
        '        If tag < TimeTicks() Then
        '            chk.BackColor = SystemColors.Control
        '            chk.ForeColor = SystemColors.ControlText
        '            chk.Tag = 0
        '        End If
        '    End If
        'Next
    End Sub

    Private Sub WriteAll()
        Model.WriteAll()
        UpdateModel()
    End Sub

    Private Sub ReadAll()
        UpdateModel()
    End Sub

    Private Sub ResetDevice()
        UpdateModel()
    End Sub

    Private Sub AddInterruptChkHandlers()
        For Each chk As CheckBox In grpRaised.Controls.OfType(Of CheckBox)()
            AddHandler chk.CheckedChanged, AddressOf interrupt_checkedChanged
        Next
    End Sub

    Private Sub interrupt_checkedChanged(sender As System.Object, e As System.EventArgs)
        Dim chk As CheckBox = TryCast(sender, CheckBox)
        If chk IsNot Nothing Then
            If chk.Checked Then
                chk.BackColor = Color.Red
                chk.ForeColor = Color.White
                'chk.Tag = TimeTicks() + 1000
            Else
                chk.BackColor = SystemColors.Control
                chk.ForeColor = SystemColors.ControlText
            End If
        End If
    End Sub

    Private Sub tsmAbout_Click(sender As System.Object, e As System.EventArgs) Handles tsmAbout.Click
        frmAbout.Show(Me)
    End Sub

    Private Sub tsmRead_Click(sender As System.Object, e As System.EventArgs) Handles tsmRead.Click
        ReadAll()
    End Sub

    Private Sub tsmWrite_Click(sender As System.Object, e As System.EventArgs) Handles tsmWrite.Click
        WriteAll()
    End Sub

    Private Sub tsbWrite_Click(sender As System.Object, e As System.EventArgs) Handles tsbWrite.Click
        WriteAll()
    End Sub

    Private Sub tsbReset_Click(sender As System.Object, e As System.EventArgs) Handles tsbReset.Click
        ResetDevice()
    End Sub

    Private Sub tsmReset_Click(sender As System.Object, e As System.EventArgs) Handles tsmReset.Click
        ResetDevice()
    End Sub

    Private Sub SetAutoRefresh(interval As UInteger)
        tsmInterval0.Checked = False
        tsmInterval1.Checked = False
        tsmInterval2.Checked = False
        tsmInterval4.Checked = False
        Select Case interval
            Case 0
                tsmInterval0.Checked = True
                tscRefresh.SelectedIndex = 0
                m_statusReadInterval = 0
            Case 1
                tsmInterval1.Checked = True
                tscRefresh.SelectedIndex = 1
                m_statusReadInterval = 1000
            Case 2
                tsmInterval2.Checked = True
                tscRefresh.SelectedIndex = 2
                m_statusReadInterval = 500
            Case Else
                tsmInterval4.Checked = True
                tscRefresh.SelectedIndex = 3
                m_statusReadInterval = 250
        End Select
        My.Settings.Interval = CUInt(tscRefresh.SelectedIndex)
        My.Settings.Save()
        ScheduleStatusRead()
    End Sub

    Private Sub tsmInterval0_Click(sender As System.Object, e As System.EventArgs) Handles tsmInterval0.Click
        SetAutoRefresh(0)
    End Sub

    Private Sub tsmInterval1_Click(sender As System.Object, e As System.EventArgs) Handles tsmInterval1.Click
        SetAutoRefresh(1)
    End Sub

    Private Sub tsmInterval2_Click(sender As System.Object, e As System.EventArgs) Handles tsmInterval2.Click
        SetAutoRefresh(2)
    End Sub

    Private Sub tsmInterval4_Click(sender As System.Object, e As System.EventArgs) Handles tsmInterval4.Click
        SetAutoRefresh(4)
    End Sub

    Private Sub tscRefresh_SelectedIndexChanged(sender As Object, e As System.EventArgs) Handles tscRefresh.SelectedIndexChanged
        If tscRefresh.SelectedIndex >= 0 Then SetAutoRefresh(CUInt(tscRefresh.SelectedIndex))
    End Sub

    Private Sub tsbRead_Click(sender As System.Object, e As System.EventArgs) Handles tsbRead.Click
        ReadAll()
    End Sub

    Private Sub BuildRegisterMap()
        Const xOffset As Integer = 16
        Const yOffset As Integer = 10
        Dim row As Integer = 0, col As Integer = 0, offset As Integer = 0
        Dim txt As TextBox, lblRegName As Label
        Dim v As View
        For fld As pca_data_fields_enum_t = pca_data_fields_enum_t.reg_0 To pca_data_fields_enum_t.reg_f
            lblRegName = New Label With {.Location = New Point(col * 187 + xOffset, 3 + yOffset + 24 * row), .Size = New Size(126, 20)}
            txt = New TextBox With {.Location = New Point(col * 187 + xOffset + 134, yOffset + 24 * row), .Size = New Size(40, 20)}
            v = New View(txt, fld)
            txt.Enabled = Not New mvc.DataField(fld).IsReadOnly
            lblRegName.Text = "0x" & Strings.Right("0" & Hex(offset), 2) & "   " & mvc.Model.Caption(fld)
            pnlRegisters.Controls.Add(lblRegName)
            pnlRegisters.Controls.Add(txt)
            offset += 1
            row += 1
            If yOffset + 24 * row > pnlRegisters.Height - 24 Then
                row = 0
                col += 1
            End If
        Next
    End Sub

    Private Sub SetView(v As ViewEnum)
        pnlFunctions.Visible = v = ViewEnum.ve_Functional
        pnlRegisters.Visible = v <> ViewEnum.ve_Functional
        tsbFunctions.Checked = v = ViewEnum.ve_Functional
        tsmFunctions.Checked = v = ViewEnum.ve_Functional
        tsbRegisters.Checked = v <> ViewEnum.ve_Functional
        tsmRegisters.Checked = v <> ViewEnum.ve_Functional
    End Sub

    Private Sub tsmFunctions_Click(sender As System.Object, e As System.EventArgs) Handles tsmFunctions.Click
        SetView(ViewEnum.ve_Functional)
    End Sub

    Private Sub tsmRegisters_Click(sender As System.Object, e As System.EventArgs) Handles tsmRegisters.Click
        SetView(ViewEnum.ve_RegisterMap)
    End Sub

    Private Sub tsbFunctions_Click(sender As System.Object, e As System.EventArgs) Handles tsbFunctions.Click
        SetView(ViewEnum.ve_Functional)
    End Sub

    Private Sub tsbRegisters_Click(sender As System.Object, e As System.EventArgs) Handles tsbRegisters.Click
        SetView(ViewEnum.ve_RegisterMap)
    End Sub

    Private Sub btnCtrlRead_Click(sender As Object, e As EventArgs) Handles btnCtrlRead.Click
        ReadAll()
    End Sub

    Private Sub btnCtrlSet_Click(sender As Object, e As EventArgs) Handles btnCtrlSet.Click
        WriteAll()
    End Sub

    Private Sub btnReadInt_Click(sender As Object, e As EventArgs) Handles btnReadInt.Click
        ReadAll()
    End Sub

    Private Sub btnSetInt_Click(sender As Object, e As EventArgs) Handles btnSetInt.Click
        WriteAll()
    End Sub

    Private Sub btnVinDetCtrlRead_Click(sender As Object, e As EventArgs) Handles btnVinDetCtrlRead.Click
        ReadAll()
    End Sub

    Private Sub btnVinDetCtrlSet_Click(sender As Object, e As EventArgs) Handles btnVinDetCtrlSet.Click
        WriteAll()
    End Sub
End Class
