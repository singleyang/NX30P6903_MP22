Imports System.Windows.Forms
Imports nx30p6903_mp22_fields
Imports System.Globalization

Public Class View

    Const textbased As Integer = &H100

    Private Enum ViewType
        none
        chkbox
        dropdownlist
        slider
        radio
        label = textbased
        textbox
    End Enum

    Private m_ctrl As Control
    Private m_data As DataField
    Private m_type As ViewType
    Private m_value As Integer = 0  ' value for radio buttons

    Friend ReadOnly Property Field As DataField
        Get
            Return m_data
        End Get
    End Property

    Friend ReadOnly Property Ctrl As Control
        Get
            Return m_ctrl
        End Get
    End Property

    Private ReadOnly Property IsTextBasedControl As Boolean
        Get
            Return m_type >= textbased
        End Get
    End Property

    Private Delegate Sub textboxText(ctrl As TextBox, txt As String)
    Private Sub SetTextboxText(ctrl As TextBox, txt As String)
        If ctrl.InvokeRequired Then
            Dim ctrlText As New textboxText(AddressOf SetTextboxText)
            'ctrl.BeginInvoke(ctrlText, New Object() {txt})
            If ctrl.Created Then ctrl.BeginInvoke(ctrlText, New Object() {ctrl, txt})
        Else
            If ctrl IsNot Nothing AndAlso txt <> ctrl.Text Then ctrl.Text = txt
        End If
    End Sub

    Private Delegate Sub chkboxCheck(ctrl As CheckBox, chk As Integer)
    Private Sub SetCheckboxCheck(ctrl As CheckBox, chk As Integer)
        If ctrl.InvokeRequired Then
            Dim ctrlCheck As New chkboxCheck(AddressOf SetCheckboxCheck)
            'ctrl.BeginInvoke(ctrlCheck, New Object() {chk})
            If ctrl.Created Then ctrl.BeginInvoke(ctrlCheck, New Object() {ctrl, chk})
        Else
            If ctrl IsNot Nothing AndAlso ctrl.Checked = (chk = 0) Then ctrl.Checked = Not ctrl.Checked
        End If
    End Sub

    Private Delegate Sub cmbboxValue(ctrl As ComboBox, val As Integer)
    Private Sub SetCmbboxVal(ctrl As ComboBox, val As Integer)
        If ctrl.InvokeRequired Then
            Dim ctrlVal As New cmbboxValue(AddressOf SetCmbboxVal)
            'ctrl.BeginInvoke(ctrlVal, New Object() {val})
            If ctrl.Created Then ctrl.BeginInvoke(ctrlVal, New Object() {ctrl, val})
        Else
            If ctrl IsNot Nothing AndAlso ctrl.SelectedIndex <> val Then ctrl.SelectedIndex = val
        End If
    End Sub

    Private Delegate Sub labelText(lbl As Label, txt As String)
    Private Sub SetLabelText(lbl As Label, txt As String)
        If lbl.InvokeRequired Then
            Dim lblText As New labelText(AddressOf SetLabelText)
            lbl.BeginInvoke(lblText, New Object() {lbl, txt})
        Else
            If lbl IsNot Nothing AndAlso txt <> lbl.Text Then lbl.Text = txt
        End If
    End Sub

    Private Sub UpdateControl()
        Dim text As String = ""
        Dim value As Integer = 0
        If (IsTextBasedControl) Then
            text = m_data.CurrentValueText
        Else
            value = m_data.CurrentValue
        End If
        Select Case (m_type)
            Case ViewType.textbox
                Dim txt As TextBox = TryCast(m_ctrl, TextBox)
                SetTextboxText(txt, text)
            Case ViewType.chkbox
                Dim chk As CheckBox = TryCast(m_ctrl, CheckBox)
                SetCheckboxCheck(chk, value)
            Case ViewType.dropdownlist
                Dim cmb As ComboBox = TryCast(m_ctrl, ComboBox)
                'If cmb IsNot Nothing AndAlso cmb.SelectedIndex <> value Then SetCmbboxVal(cmb, value)
                SetCmbboxVal(cmb, value)
            Case ViewType.label
                Dim lbl As Label = TryCast(m_ctrl, Label)
                SetLabelText(lbl, text)
            Case ViewType.slider
                Dim trb As TrackBar = TryCast(m_ctrl, TrackBar)
                If trb IsNot Nothing AndAlso trb.Value <> value _
                    AndAlso value <= trb.Maximum AndAlso value >= trb.Minimum Then trb.Value = value
            Case ViewType.radio
                Dim rb As RadioButton = TryCast(m_ctrl, RadioButton)
                If rb IsNot Nothing Then
                    rb.Checked = value = m_value
                End If
        End Select
    End Sub

    Friend Sub DataChanged()
        UpdateControl()
    End Sub

    Private Sub TextBoxUpdated()
        Dim tb As TextBox = TryCast(m_ctrl, TextBox)
        If tb IsNot Nothing Then
            Dim ns As NumberStyles = NumberStyles.Integer
            Dim valStr As String = tb.Text
            If InStr(valStr, "0x") <> 0 Then
                ns = NumberStyles.HexNumber
                valStr = Replace(valStr, "0x", "")
            End If
            Dim value As Integer
            If Integer.TryParse(valStr, ns, CultureInfo.CurrentCulture, value) Then
                If value <> m_data.CurrentValue Then m_data.CurrentValue = value
            Else
                tb.Text = m_data.CurrentValueText
            End If
        End If

    End Sub

    Private Sub ComboBox_ChangeCommitted(ByVal Sender As Object, ByVal e As System.EventArgs)
        Dim cmb As ComboBox = TryCast(m_ctrl, ComboBox)
        If cmb IsNot Nothing AndAlso cmb.SelectedIndex >= 0 Then
            m_data.CurrentValue = cmb.SelectedIndex
        End If
    End Sub

    Private Sub ChkBox_CheckChanged(ByVal Sender As Object, ByVal e As System.EventArgs)
        Dim chk As CheckBox = TryCast(m_ctrl, CheckBox)
        If chk IsNot Nothing Then
            'If m_data.IsReadOnly Then
            '    UpdateControl()
            'Else
            '    m_data.CurrentValue = CInt(IIf(chk.Checked, 1, 0))
            'End If
            m_data.CurrentValue = CInt(IIf(chk.Checked, 1, 0))
        End If
    End Sub

    Private Sub RadioBtn_CheckChanged(ByVal Sender As Object, ByVal e As System.EventArgs)
        Dim rbt As RadioButton = TryCast(m_ctrl, RadioButton)
        If rbt IsNot Nothing Then
            If rbt.Checked Then
                m_data.CurrentValue = m_value
            End If
        End If
    End Sub

    Private Sub TrackBar_ValueChanged(ByVal Sender As Object, ByVal e As System.EventArgs)
        Dim tb As TrackBar = TryCast(m_ctrl, TrackBar)
        If tb IsNot Nothing AndAlso tb.Value <> m_data.CurrentValue Then m_data.CurrentValue = tb.Value
    End Sub

    Private Sub Textbox_LostFocus(ByVal Sender As Object, ByVal e As System.EventArgs)
        TextBoxUpdated()
    End Sub

    Private Sub Textbox_KeyDown(ByVal Sender As Object, ByVal e As KeyEventArgs)
        Dim tb As TextBox = TryCast(m_ctrl, TextBox)
        If tb IsNot Nothing Then
            If e.KeyCode = Keys.Return Then
                e.Handled = True
                e.SuppressKeyPress = True
                TextBoxUpdated()
            End If
        End If
    End Sub

    Private Sub InitComboBox(cmb As ComboBox)
        cmb.Items.Clear()
        cmb.DropDownStyle = ComboBoxStyle.DropDownList
        cmb.BeginUpdate()
        Dim idx As Integer
        For idx = 0 To m_data.ValueCount - 1
            cmb.Items.Add(m_data.ValueText(idx))
        Next
        cmb.EndUpdate()
        AddHandler cmb.SelectionChangeCommitted, AddressOf ComboBox_ChangeCommitted
    End Sub

    Private Sub InitTrackBar(tb As TrackBar)
        Dim vc As Integer = m_data.ValueCount
        tb.SetRange(0, vc - 1)
        tb.TickFrequency = 1
        While ((vc * 4) \ tb.TickFrequency > tb.ClientSize.Width)
            tb.TickFrequency += 1
        End While
        tb.SmallChange = 1
        tb.LargeChange = CInt(IIf(vc > 10, vc \ 10, 1))
        AddHandler tb.ValueChanged, AddressOf TrackBar_ValueChanged
    End Sub

    Public Sub New(ctrl As TextBox, Field As pca_data_fields_enum_t)
        m_ctrl = ctrl
        m_type = ViewType.textbox
        m_data = New DataField(Field)
        AddHandler ctrl.LostFocus, AddressOf Textbox_LostFocus
        AddHandler ctrl.KeyDown, AddressOf Textbox_KeyDown
        UpdateControl()
        Model.Register(Me)
    End Sub

    Public Sub New(ctrl As CheckBox, Field As pca_data_fields_enum_t)
        m_ctrl = ctrl
        m_type = ViewType.chkbox
        m_data = New DataField(Field)
        AddHandler ctrl.CheckedChanged, AddressOf ChkBox_CheckChanged
        ctrl.Text = m_data.Caption
        'ctrl.Enabled = Not m_data.IsReadOnly
        UpdateControl()
        Model.Register(Me)
    End Sub

    Public Sub New(ctrl As ComboBox, Field As pca_data_fields_enum_t)
        m_ctrl = ctrl
        m_type = ViewType.dropdownlist
        m_data = New DataField(Field)
        InitComboBox(ctrl)
        UpdateControl()
        Model.Register(Me)
    End Sub

    Public Sub New(ctrl As Label, Field As pca_data_fields_enum_t)
        m_ctrl = ctrl
        m_type = ViewType.label
        m_data = New DataField(Field)
        UpdateControl()
        Model.Register(Me)
    End Sub

    Public Sub New(ctrl As TrackBar, Field As pca_data_fields_enum_t)
        m_ctrl = ctrl
        m_type = ViewType.slider
        m_data = New DataField(Field)
        InitTrackBar(ctrl)
        UpdateControl()
        Model.Register(Me)
    End Sub

    Public Sub New(ctrl As RadioButton, Field As pca_data_fields_enum_t, value As Integer)
        m_ctrl = ctrl
        m_type = ViewType.radio
        m_data = New DataField(Field)
        m_value = value
        AddHandler ctrl.CheckedChanged, AddressOf RadioBtn_CheckChanged
        ctrl.Text = m_data.ValueText(value)
        UpdateControl()
        Model.Register(Me)
    End Sub

    Protected Overrides Sub Finalize()
        Select Case m_type
            Case ViewType.chkbox
                Dim chk As CheckBox = TryCast(m_ctrl, CheckBox)
                If chk IsNot Nothing Then RemoveHandler chk.CheckedChanged, AddressOf ChkBox_CheckChanged
            Case ViewType.dropdownlist
                Dim cmb As ComboBox = TryCast(m_ctrl, ComboBox)
                If cmb IsNot Nothing Then RemoveHandler cmb.SelectionChangeCommitted, AddressOf ComboBox_ChangeCommitted
        End Select
        MyBase.Finalize()
    End Sub


End Class
