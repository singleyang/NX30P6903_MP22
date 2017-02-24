<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class frmMain_mp22
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(frmMain_mp22))
        Me.StatusStrip1 = New System.Windows.Forms.StatusStrip()
        Me.tslConnection = New System.Windows.Forms.ToolStripStatusLabel()
        Me.tslInterface = New System.Windows.Forms.ToolStripStatusLabel()
        Me.tmrWork = New System.Windows.Forms.Timer(Me.components)
        Me.grpDevice = New System.Windows.Forms.GroupBox()
        Me.lblRev = New System.Windows.Forms.Label()
        Me.lblId = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.lblAddr = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.TheMenu = New System.Windows.Forms.MenuStrip()
        Me.tsmView = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmFunctions = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmRegisters = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmIO = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmRead = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmWrite = New System.Windows.Forms.ToolStripMenuItem()
        Me.ToolStripSeparator1 = New System.Windows.Forms.ToolStripSeparator()
        Me.tsmReset = New System.Windows.Forms.ToolStripMenuItem()
        Me.ToolStripSeparator2 = New System.Windows.Forms.ToolStripSeparator()
        Me.tsmRefresh = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmInterval0 = New System.Windows.Forms.ToolStripMenuItem()
        Me.ToolStripSeparator3 = New System.Windows.Forms.ToolStripSeparator()
        Me.tsmInterval1 = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmInterval2 = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmInterval4 = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmHelp = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmAbout = New System.Windows.Forms.ToolStripMenuItem()
        Me.tsmManual = New System.Windows.Forms.ToolStripMenuItem()
        Me.theToolbar = New System.Windows.Forms.ToolStrip()
        Me.tsbWrite = New System.Windows.Forms.ToolStripButton()
        Me.tsbRead = New System.Windows.Forms.ToolStripButton()
        Me.ToolStripSeparator4 = New System.Windows.Forms.ToolStripSeparator()
        Me.tsbReset = New System.Windows.Forms.ToolStripButton()
        Me.ToolStripSeparator5 = New System.Windows.Forms.ToolStripSeparator()
        Me.tsbFunctions = New System.Windows.Forms.ToolStripButton()
        Me.tsbRegisters = New System.Windows.Forms.ToolStripButton()
        Me.ToolStripSeparator6 = New System.Windows.Forms.ToolStripSeparator()
        Me.tsbRefresh = New System.Windows.Forms.ToolStripLabel()
        Me.tscRefresh = New System.Windows.Forms.ToolStripComboBox()
        Me.pnlFunctions = New System.Windows.Forms.Panel()
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.chkSwitchOnSts = New System.Windows.Forms.CheckBox()
        Me.chkTimeOutSts = New System.Windows.Forms.CheckBox()
        Me.chkOverTagSts = New System.Windows.Forms.CheckBox()
        Me.chkPwrOnSts = New System.Windows.Forms.CheckBox()
        Me.grpRaised = New System.Windows.Forms.GroupBox()
        Me.chkOTflag = New System.Windows.Forms.CheckBox()
        Me.chkOCflag = New System.Windows.Forms.CheckBox()
        Me.chkOVflag = New System.Windows.Forms.CheckBox()
        Me.grpAdcChannels = New System.Windows.Forms.GroupBox()
        Me.lblVinAdc = New System.Windows.Forms.Label()
        Me.txtVinAdc = New System.Windows.Forms.TextBox()
        Me.TabControl2 = New System.Windows.Forms.TabControl()
        Me.tbpControl = New System.Windows.Forms.TabPage()
        Me.btnCtrlRead = New System.Windows.Forms.Button()
        Me.btnCtrlSet = New System.Windows.Forms.Button()
        Me.chkDetectEn = New System.Windows.Forms.CheckBox()
        Me.lblVinTagRegVal = New System.Windows.Forms.Label()
        Me.trbVinTagReg = New System.Windows.Forms.TrackBar()
        Me.lblVinTagReg = New System.Windows.Forms.Label()
        Me.lblVinDutyReg = New System.Windows.Forms.Label()
        Me.lblIsrcDetReg = New System.Windows.Forms.Label()
        Me.lblIsrcReg = New System.Windows.Forms.Label()
        Me.chkVoutEn = New System.Windows.Forms.CheckBox()
        Me.cmbOvloThres = New System.Windows.Forms.ComboBox()
        Me.lblOvloThres = New System.Windows.Forms.Label()
        Me.cmbOvloSel = New System.Windows.Forms.ComboBox()
        Me.lblOvloSel = New System.Windows.Forms.Label()
        Me.cmbOvloRng = New System.Windows.Forms.ComboBox()
        Me.lblOvloRng = New System.Windows.Forms.Label()
        Me.Interrupt = New System.Windows.Forms.TabPage()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.btnReadInt = New System.Windows.Forms.Button()
        Me.btnSetInt = New System.Windows.Forms.Button()
        Me.chkOTMask = New System.Windows.Forms.CheckBox()
        Me.chkOCMask = New System.Windows.Forms.CheckBox()
        Me.chkOVMask = New System.Windows.Forms.CheckBox()
        Me.chkSwitchOnMask = New System.Windows.Forms.CheckBox()
        Me.chkTimerOutMask = New System.Windows.Forms.CheckBox()
        Me.chkPwrOnMask = New System.Windows.Forms.CheckBox()
        Me.chkOverTagMask = New System.Windows.Forms.CheckBox()
        Me.pnlRegisters = New System.Windows.Forms.Panel()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.cmbIsrcVal = New System.Windows.Forms.ComboBox()
        Me.cmbIsrcDet = New System.Windows.Forms.ComboBox()
        Me.cmbVinDuty = New System.Windows.Forms.ComboBox()
        Me.StatusStrip1.SuspendLayout()
        Me.grpDevice.SuspendLayout()
        Me.TheMenu.SuspendLayout()
        Me.theToolbar.SuspendLayout()
        Me.pnlFunctions.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.grpRaised.SuspendLayout()
        Me.grpAdcChannels.SuspendLayout()
        Me.TabControl2.SuspendLayout()
        Me.tbpControl.SuspendLayout()
        CType(Me.trbVinTagReg, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Interrupt.SuspendLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'StatusStrip1
        '
        Me.StatusStrip1.ImageScalingSize = New System.Drawing.Size(20, 20)
        Me.StatusStrip1.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tslConnection, Me.tslInterface})
        Me.StatusStrip1.Location = New System.Drawing.Point(0, 568)
        Me.StatusStrip1.Name = "StatusStrip1"
        Me.StatusStrip1.Padding = New System.Windows.Forms.Padding(1, 0, 19, 0)
        Me.StatusStrip1.Size = New System.Drawing.Size(781, 25)
        Me.StatusStrip1.SizingGrip = False
        Me.StatusStrip1.TabIndex = 0
        Me.StatusStrip1.Text = "StatusStrip1"
        '
        'tslConnection
        '
        Me.tslConnection.Image = CType(resources.GetObject("tslConnection.Image"), System.Drawing.Image)
        Me.tslConnection.Name = "tslConnection"
        Me.tslConnection.Size = New System.Drawing.Size(119, 20)
        Me.tslConnection.Text = "Disconnected"
        '
        'tslInterface
        '
        Me.tslInterface.Name = "tslInterface"
        Me.tslInterface.Size = New System.Drawing.Size(642, 20)
        Me.tslInterface.Spring = True
        Me.tslInterface.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'tmrWork
        '
        '
        'grpDevice
        '
        Me.grpDevice.Controls.Add(Me.lblRev)
        Me.grpDevice.Controls.Add(Me.lblId)
        Me.grpDevice.Controls.Add(Me.Label5)
        Me.grpDevice.Controls.Add(Me.Label4)
        Me.grpDevice.Controls.Add(Me.lblAddr)
        Me.grpDevice.Controls.Add(Me.Label2)
        Me.grpDevice.Location = New System.Drawing.Point(16, 64)
        Me.grpDevice.Margin = New System.Windows.Forms.Padding(4)
        Me.grpDevice.Name = "grpDevice"
        Me.grpDevice.Padding = New System.Windows.Forms.Padding(4)
        Me.grpDevice.Size = New System.Drawing.Size(449, 59)
        Me.grpDevice.TabIndex = 22
        Me.grpDevice.TabStop = False
        Me.grpDevice.Text = "Device"
        '
        'lblRev
        '
        Me.lblRev.AutoSize = True
        Me.lblRev.Location = New System.Drawing.Point(376, 28)
        Me.lblRev.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblRev.Name = "lblRev"
        Me.lblRev.Size = New System.Drawing.Size(18, 17)
        Me.lblRev.TabIndex = 8
        Me.lblRev.Text = "--"
        '
        'lblId
        '
        Me.lblId.AutoSize = True
        Me.lblId.Location = New System.Drawing.Point(237, 28)
        Me.lblId.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblId.Name = "lblId"
        Me.lblId.Size = New System.Drawing.Size(18, 17)
        Me.lblId.TabIndex = 7
        Me.lblId.Text = "--"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(304, 28)
        Me.Label5.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(66, 17)
        Me.Label5.TabIndex = 6
        Me.Label5.Text = "Revision:"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(205, 28)
        Me.Label4.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(25, 17)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "ID:"
        '
        'lblAddr
        '
        Me.lblAddr.AutoSize = True
        Me.lblAddr.Location = New System.Drawing.Point(99, 28)
        Me.lblAddr.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblAddr.Name = "lblAddr"
        Me.lblAddr.Size = New System.Drawing.Size(18, 17)
        Me.lblAddr.TabIndex = 4
        Me.lblAddr.Text = "--"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(31, 28)
        Me.Label2.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(64, 17)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Address:"
        '
        'TheMenu
        '
        Me.TheMenu.ImageScalingSize = New System.Drawing.Size(20, 20)
        Me.TheMenu.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsmView, Me.tsmIO, Me.tsmHelp})
        Me.TheMenu.Location = New System.Drawing.Point(0, 0)
        Me.TheMenu.Name = "TheMenu"
        Me.TheMenu.Padding = New System.Windows.Forms.Padding(8, 2, 0, 2)
        Me.TheMenu.Size = New System.Drawing.Size(781, 28)
        Me.TheMenu.TabIndex = 2
        Me.TheMenu.Text = "MenuStrip1"
        '
        'tsmView
        '
        Me.tsmView.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsmFunctions, Me.tsmRegisters})
        Me.tsmView.Name = "tsmView"
        Me.tsmView.Size = New System.Drawing.Size(53, 24)
        Me.tsmView.Text = "&View"
        '
        'tsmFunctions
        '
        Me.tsmFunctions.Image = Global.NX30P6093_MP22.My.Resources.Resources._function
        Me.tsmFunctions.Name = "tsmFunctions"
        Me.tsmFunctions.ShortcutKeys = System.Windows.Forms.Keys.F8
        Me.tsmFunctions.Size = New System.Drawing.Size(194, 26)
        Me.tsmFunctions.Text = "&Functions"
        Me.tsmFunctions.ToolTipText = "Functional view of register map"
        '
        'tsmRegisters
        '
        Me.tsmRegisters.Image = Global.NX30P6093_MP22.My.Resources.Resources.table
        Me.tsmRegisters.Name = "tsmRegisters"
        Me.tsmRegisters.ShortcutKeys = System.Windows.Forms.Keys.F9
        Me.tsmRegisters.Size = New System.Drawing.Size(194, 26)
        Me.tsmRegisters.Text = "&Register map"
        Me.tsmRegisters.ToolTipText = "Registers values in hexadecimal and binary"
        '
        'tsmIO
        '
        Me.tsmIO.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsmRead, Me.tsmWrite, Me.ToolStripSeparator1, Me.tsmReset, Me.ToolStripSeparator2, Me.tsmRefresh})
        Me.tsmIO.Name = "tsmIO"
        Me.tsmIO.Size = New System.Drawing.Size(36, 24)
        Me.tsmIO.Text = "&IO"
        '
        'tsmRead
        '
        Me.tsmRead.Image = Global.NX30P6093_MP22.My.Resources.Resources.spectacle
        Me.tsmRead.Name = "tsmRead"
        Me.tsmRead.ShortcutKeys = System.Windows.Forms.Keys.F5
        Me.tsmRead.Size = New System.Drawing.Size(163, 26)
        Me.tsmRead.Text = "&Read all"
        Me.tsmRead.ToolTipText = "Read all registers"
        '
        'tsmWrite
        '
        Me.tsmWrite.Image = Global.NX30P6093_MP22.My.Resources.Resources.pencil__arrow
        Me.tsmWrite.Name = "tsmWrite"
        Me.tsmWrite.ShortcutKeys = System.Windows.Forms.Keys.F6
        Me.tsmWrite.Size = New System.Drawing.Size(163, 26)
        Me.tsmWrite.Text = "&Write all"
        Me.tsmWrite.ToolTipText = "Write all registers"
        '
        'ToolStripSeparator1
        '
        Me.ToolStripSeparator1.Name = "ToolStripSeparator1"
        Me.ToolStripSeparator1.Size = New System.Drawing.Size(160, 6)
        '
        'tsmReset
        '
        Me.tsmReset.Image = Global.NX30P6093_MP22.My.Resources.Resources.counter_reset
        Me.tsmReset.Name = "tsmReset"
        Me.tsmReset.ShortcutKeys = System.Windows.Forms.Keys.F7
        Me.tsmReset.Size = New System.Drawing.Size(163, 26)
        Me.tsmReset.Text = "Re&set"
        Me.tsmReset.ToolTipText = "Reset PCA949x to defaults"
        '
        'ToolStripSeparator2
        '
        Me.ToolStripSeparator2.Name = "ToolStripSeparator2"
        Me.ToolStripSeparator2.Size = New System.Drawing.Size(160, 6)
        '
        'tsmRefresh
        '
        Me.tsmRefresh.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsmInterval0, Me.ToolStripSeparator3, Me.tsmInterval1, Me.tsmInterval2, Me.tsmInterval4})
        Me.tsmRefresh.Image = Global.NX30P6093_MP22.My.Resources.Resources.clock
        Me.tsmRefresh.Name = "tsmRefresh"
        Me.tsmRefresh.Size = New System.Drawing.Size(163, 26)
        Me.tsmRefresh.Text = "&Auto refresh"
        Me.tsmRefresh.ToolTipText = "Refresh interval for ADC and interrupts"
        '
        'tsmInterval0
        '
        Me.tsmInterval0.Name = "tsmInterval0"
        Me.tsmInterval0.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.D0), System.Windows.Forms.Keys)
        Me.tsmInterval0.Size = New System.Drawing.Size(260, 24)
        Me.tsmInterval0.Text = "&Disabled"
        Me.tsmInterval0.ToolTipText = "Registers are read manually"
        '
        'ToolStripSeparator3
        '
        Me.ToolStripSeparator3.Name = "ToolStripSeparator3"
        Me.ToolStripSeparator3.Size = New System.Drawing.Size(257, 6)
        '
        'tsmInterval1
        '
        Me.tsmInterval1.Name = "tsmInterval1"
        Me.tsmInterval1.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.D1), System.Windows.Forms.Keys)
        Me.tsmInterval1.Size = New System.Drawing.Size(260, 24)
        Me.tsmInterval1.Text = "&Once a second"
        Me.tsmInterval1.ToolTipText = "Read ADC and interrupts once a second"
        '
        'tsmInterval2
        '
        Me.tsmInterval2.Name = "tsmInterval2"
        Me.tsmInterval2.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.D2), System.Windows.Forms.Keys)
        Me.tsmInterval2.Size = New System.Drawing.Size(260, 24)
        Me.tsmInterval2.Text = "&Twice a second"
        Me.tsmInterval2.ToolTipText = "Read ADC and interrupts twice a second"
        '
        'tsmInterval4
        '
        Me.tsmInterval4.Name = "tsmInterval4"
        Me.tsmInterval4.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.D4), System.Windows.Forms.Keys)
        Me.tsmInterval4.Size = New System.Drawing.Size(260, 24)
        Me.tsmInterval4.Text = "&Four times a second"
        Me.tsmInterval4.ToolTipText = "Read ADC and interrupts four times a second"
        '
        'tsmHelp
        '
        Me.tsmHelp.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsmAbout, Me.tsmManual})
        Me.tsmHelp.Name = "tsmHelp"
        Me.tsmHelp.Size = New System.Drawing.Size(53, 24)
        Me.tsmHelp.Text = "&Help"
        '
        'tsmAbout
        '
        Me.tsmAbout.Image = Global.NX30P6093_MP22.My.Resources.Resources.information
        Me.tsmAbout.Name = "tsmAbout"
        Me.tsmAbout.ShortcutKeyDisplayString = ""
        Me.tsmAbout.Size = New System.Drawing.Size(262, 26)
        Me.tsmAbout.Text = "About..."
        Me.tsmAbout.ToolTipText = "Version and file information"
        '
        'tsmManual
        '
        Me.tsmManual.Image = Global.NX30P6093_MP22.My.Resources.Resources.book_question
        Me.tsmManual.Name = "tsmManual"
        Me.tsmManual.ShortcutKeys = System.Windows.Forms.Keys.F1
        Me.tsmManual.Size = New System.Drawing.Size(262, 26)
        Me.tsmManual.Text = "Open the User Manual..."
        Me.tsmManual.ToolTipText = "Open the User Manual with an external PDF viewer"
        '
        'theToolbar
        '
        Me.theToolbar.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden
        Me.theToolbar.ImageScalingSize = New System.Drawing.Size(20, 20)
        Me.theToolbar.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.tsbWrite, Me.tsbRead, Me.ToolStripSeparator4, Me.tsbReset, Me.ToolStripSeparator5, Me.tsbFunctions, Me.tsbRegisters, Me.ToolStripSeparator6, Me.tsbRefresh, Me.tscRefresh})
        Me.theToolbar.Location = New System.Drawing.Point(0, 28)
        Me.theToolbar.Name = "theToolbar"
        Me.theToolbar.RenderMode = System.Windows.Forms.ToolStripRenderMode.Professional
        Me.theToolbar.Size = New System.Drawing.Size(781, 28)
        Me.theToolbar.TabIndex = 3
        Me.theToolbar.Text = "ToolStrip1"
        '
        'tsbWrite
        '
        Me.tsbWrite.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.tsbWrite.Image = Global.NX30P6093_MP22.My.Resources.Resources.pencil__arrow
        Me.tsbWrite.ImageTransparentColor = System.Drawing.Color.Magenta
        Me.tsbWrite.Name = "tsbWrite"
        Me.tsbWrite.Size = New System.Drawing.Size(24, 25)
        Me.tsbWrite.Text = "Write all"
        Me.tsbWrite.ToolTipText = "Write all registers"
        '
        'tsbRead
        '
        Me.tsbRead.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.tsbRead.Image = Global.NX30P6093_MP22.My.Resources.Resources.spectacle
        Me.tsbRead.ImageTransparentColor = System.Drawing.Color.Magenta
        Me.tsbRead.Name = "tsbRead"
        Me.tsbRead.Size = New System.Drawing.Size(24, 25)
        Me.tsbRead.Text = "Read all"
        Me.tsbRead.ToolTipText = "Read all registers"
        '
        'ToolStripSeparator4
        '
        Me.ToolStripSeparator4.Margin = New System.Windows.Forms.Padding(5, 0, 5, 0)
        Me.ToolStripSeparator4.Name = "ToolStripSeparator4"
        Me.ToolStripSeparator4.Size = New System.Drawing.Size(6, 28)
        '
        'tsbReset
        '
        Me.tsbReset.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.tsbReset.Image = Global.NX30P6093_MP22.My.Resources.Resources.counter_reset
        Me.tsbReset.ImageTransparentColor = System.Drawing.Color.Magenta
        Me.tsbReset.Name = "tsbReset"
        Me.tsbReset.Size = New System.Drawing.Size(24, 25)
        Me.tsbReset.Text = "Reset device"
        Me.tsbReset.ToolTipText = "Reset PCA949x"
        '
        'ToolStripSeparator5
        '
        Me.ToolStripSeparator5.Margin = New System.Windows.Forms.Padding(5, 0, 5, 0)
        Me.ToolStripSeparator5.Name = "ToolStripSeparator5"
        Me.ToolStripSeparator5.Size = New System.Drawing.Size(6, 28)
        '
        'tsbFunctions
        '
        Me.tsbFunctions.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.tsbFunctions.Image = Global.NX30P6093_MP22.My.Resources.Resources._function
        Me.tsbFunctions.ImageTransparentColor = System.Drawing.Color.Magenta
        Me.tsbFunctions.Name = "tsbFunctions"
        Me.tsbFunctions.Size = New System.Drawing.Size(24, 25)
        Me.tsbFunctions.Text = "Functions"
        Me.tsbFunctions.ToolTipText = "Functional view"
        '
        'tsbRegisters
        '
        Me.tsbRegisters.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image
        Me.tsbRegisters.Image = Global.NX30P6093_MP22.My.Resources.Resources.table
        Me.tsbRegisters.ImageTransparentColor = System.Drawing.Color.Magenta
        Me.tsbRegisters.Name = "tsbRegisters"
        Me.tsbRegisters.Size = New System.Drawing.Size(24, 25)
        Me.tsbRegisters.Text = "Register map"
        '
        'ToolStripSeparator6
        '
        Me.ToolStripSeparator6.Margin = New System.Windows.Forms.Padding(5, 0, 5, 0)
        Me.ToolStripSeparator6.Name = "ToolStripSeparator6"
        Me.ToolStripSeparator6.Size = New System.Drawing.Size(6, 28)
        '
        'tsbRefresh
        '
        Me.tsbRefresh.Image = Global.NX30P6093_MP22.My.Resources.Resources.clock
        Me.tsbRefresh.Name = "tsbRefresh"
        Me.tsbRefresh.Size = New System.Drawing.Size(110, 25)
        Me.tsbRefresh.Text = "Auto refresh"
        Me.tsbRefresh.ToolTipText = "Refresh interval for ADC and interrupts"
        '
        'tscRefresh
        '
        Me.tscRefresh.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.tscRefresh.Items.AddRange(New Object() {"Disabled", "1 / second", "2 / second", "4 / second"})
        Me.tscRefresh.Name = "tscRefresh"
        Me.tscRefresh.Size = New System.Drawing.Size(160, 28)
        Me.tscRefresh.ToolTipText = "Refresh interval for ADC and interrupts"
        '
        'pnlFunctions
        '
        Me.pnlFunctions.Controls.Add(Me.GroupBox1)
        Me.pnlFunctions.Controls.Add(Me.grpRaised)
        Me.pnlFunctions.Controls.Add(Me.grpAdcChannels)
        Me.pnlFunctions.Controls.Add(Me.TabControl2)
        Me.pnlFunctions.Location = New System.Drawing.Point(1, 121)
        Me.pnlFunctions.Margin = New System.Windows.Forms.Padding(4)
        Me.pnlFunctions.Name = "pnlFunctions"
        Me.pnlFunctions.Size = New System.Drawing.Size(780, 427)
        Me.pnlFunctions.TabIndex = 27
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.chkSwitchOnSts)
        Me.GroupBox1.Controls.Add(Me.chkTimeOutSts)
        Me.GroupBox1.Controls.Add(Me.chkOverTagSts)
        Me.GroupBox1.Controls.Add(Me.chkPwrOnSts)
        Me.GroupBox1.Location = New System.Drawing.Point(16, 146)
        Me.GroupBox1.Margin = New System.Windows.Forms.Padding(4)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Padding = New System.Windows.Forms.Padding(4)
        Me.GroupBox1.Size = New System.Drawing.Size(229, 182)
        Me.GroupBox1.TabIndex = 31
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Status"
        '
        'chkSwitchOnSts
        '
        Me.chkSwitchOnSts.Location = New System.Drawing.Point(19, 114)
        Me.chkSwitchOnSts.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkSwitchOnSts.Name = "chkSwitchOnSts"
        Me.chkSwitchOnSts.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkSwitchOnSts.Size = New System.Drawing.Size(192, 21)
        Me.chkSwitchOnSts.TabIndex = 39
        Me.chkSwitchOnSts.Text = "SWON_STS"
        Me.chkSwitchOnSts.UseVisualStyleBackColor = True
        '
        'chkTimeOutSts
        '
        Me.chkTimeOutSts.Location = New System.Drawing.Point(19, 87)
        Me.chkTimeOutSts.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkTimeOutSts.Name = "chkTimeOutSts"
        Me.chkTimeOutSts.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkTimeOutSts.Size = New System.Drawing.Size(192, 21)
        Me.chkTimeOutSts.TabIndex = 38
        Me.chkTimeOutSts.Text = "TMR_OUT_STS"
        Me.chkTimeOutSts.UseVisualStyleBackColor = True
        '
        'chkOverTagSts
        '
        Me.chkOverTagSts.Location = New System.Drawing.Point(19, 59)
        Me.chkOverTagSts.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkOverTagSts.Name = "chkOverTagSts"
        Me.chkOverTagSts.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkOverTagSts.Size = New System.Drawing.Size(192, 21)
        Me.chkOverTagSts.TabIndex = 37
        Me.chkOverTagSts.Text = "OVER_TAG_STS"
        Me.chkOverTagSts.UseVisualStyleBackColor = True
        '
        'chkPwrOnSts
        '
        Me.chkPwrOnSts.Location = New System.Drawing.Point(19, 31)
        Me.chkPwrOnSts.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkPwrOnSts.Name = "chkPwrOnSts"
        Me.chkPwrOnSts.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkPwrOnSts.Size = New System.Drawing.Size(192, 21)
        Me.chkPwrOnSts.TabIndex = 36
        Me.chkPwrOnSts.Text = "PWRON_STS"
        Me.chkPwrOnSts.UseVisualStyleBackColor = True
        '
        'grpRaised
        '
        Me.grpRaised.Controls.Add(Me.chkOTflag)
        Me.grpRaised.Controls.Add(Me.chkOCflag)
        Me.grpRaised.Controls.Add(Me.chkOVflag)
        Me.grpRaised.Location = New System.Drawing.Point(16, 4)
        Me.grpRaised.Margin = New System.Windows.Forms.Padding(4)
        Me.grpRaised.Name = "grpRaised"
        Me.grpRaised.Padding = New System.Windows.Forms.Padding(4)
        Me.grpRaised.Size = New System.Drawing.Size(229, 134)
        Me.grpRaised.TabIndex = 28
        Me.grpRaised.TabStop = False
        Me.grpRaised.Text = "Raised interrupts"
        '
        'chkOTflag
        '
        Me.chkOTflag.Location = New System.Drawing.Point(19, 87)
        Me.chkOTflag.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkOTflag.Name = "chkOTflag"
        Me.chkOTflag.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkOTflag.Size = New System.Drawing.Size(192, 21)
        Me.chkOTflag.TabIndex = 38
        Me.chkOTflag.Text = "OT Int"
        Me.chkOTflag.UseVisualStyleBackColor = True
        '
        'chkOCflag
        '
        Me.chkOCflag.Location = New System.Drawing.Point(19, 59)
        Me.chkOCflag.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkOCflag.Name = "chkOCflag"
        Me.chkOCflag.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkOCflag.Size = New System.Drawing.Size(192, 21)
        Me.chkOCflag.TabIndex = 37
        Me.chkOCflag.Text = "OC Int"
        Me.chkOCflag.UseVisualStyleBackColor = True
        '
        'chkOVflag
        '
        Me.chkOVflag.Location = New System.Drawing.Point(19, 31)
        Me.chkOVflag.Margin = New System.Windows.Forms.Padding(3, 2, 3, 2)
        Me.chkOVflag.Name = "chkOVflag"
        Me.chkOVflag.Padding = New System.Windows.Forms.Padding(1, 0, 0, 0)
        Me.chkOVflag.Size = New System.Drawing.Size(192, 21)
        Me.chkOVflag.TabIndex = 36
        Me.chkOVflag.Text = "OV Int"
        Me.chkOVflag.UseVisualStyleBackColor = True
        '
        'grpAdcChannels
        '
        Me.grpAdcChannels.Controls.Add(Me.lblVinAdc)
        Me.grpAdcChannels.Controls.Add(Me.txtVinAdc)
        Me.grpAdcChannels.Location = New System.Drawing.Point(15, 340)
        Me.grpAdcChannels.Margin = New System.Windows.Forms.Padding(4)
        Me.grpAdcChannels.Name = "grpAdcChannels"
        Me.grpAdcChannels.Padding = New System.Windows.Forms.Padding(4)
        Me.grpAdcChannels.Size = New System.Drawing.Size(230, 73)
        Me.grpAdcChannels.TabIndex = 30
        Me.grpAdcChannels.TabStop = False
        Me.grpAdcChannels.Text = "ADC channels"
        '
        'lblVinAdc
        '
        Me.lblVinAdc.AutoSize = True
        Me.lblVinAdc.Location = New System.Drawing.Point(8, 22)
        Me.lblVinAdc.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblVinAdc.Name = "lblVinAdc"
        Me.lblVinAdc.Size = New System.Drawing.Size(79, 17)
        Me.lblVinAdc.TabIndex = 23
        Me.lblVinAdc.Text = "ISRC Value"
        '
        'txtVinAdc
        '
        Me.txtVinAdc.Location = New System.Drawing.Point(123, 19)
        Me.txtVinAdc.Margin = New System.Windows.Forms.Padding(4)
        Me.txtVinAdc.Name = "txtVinAdc"
        Me.txtVinAdc.ReadOnly = True
        Me.txtVinAdc.Size = New System.Drawing.Size(89, 22)
        Me.txtVinAdc.TabIndex = 22
        '
        'TabControl2
        '
        Me.TabControl2.Appearance = System.Windows.Forms.TabAppearance.FlatButtons
        Me.TabControl2.Controls.Add(Me.tbpControl)
        Me.TabControl2.Controls.Add(Me.Interrupt)
        Me.TabControl2.Location = New System.Drawing.Point(249, 11)
        Me.TabControl2.Margin = New System.Windows.Forms.Padding(4)
        Me.TabControl2.Name = "TabControl2"
        Me.TabControl2.SelectedIndex = 0
        Me.TabControl2.Size = New System.Drawing.Size(517, 321)
        Me.TabControl2.TabIndex = 29
        '
        'tbpControl
        '
        Me.tbpControl.BackColor = System.Drawing.SystemColors.Control
        Me.tbpControl.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.tbpControl.Controls.Add(Me.cmbVinDuty)
        Me.tbpControl.Controls.Add(Me.cmbIsrcDet)
        Me.tbpControl.Controls.Add(Me.cmbIsrcVal)
        Me.tbpControl.Controls.Add(Me.btnCtrlRead)
        Me.tbpControl.Controls.Add(Me.btnCtrlSet)
        Me.tbpControl.Controls.Add(Me.chkDetectEn)
        Me.tbpControl.Controls.Add(Me.lblVinTagRegVal)
        Me.tbpControl.Controls.Add(Me.trbVinTagReg)
        Me.tbpControl.Controls.Add(Me.lblVinTagReg)
        Me.tbpControl.Controls.Add(Me.lblVinDutyReg)
        Me.tbpControl.Controls.Add(Me.lblIsrcDetReg)
        Me.tbpControl.Controls.Add(Me.lblIsrcReg)
        Me.tbpControl.Controls.Add(Me.chkVoutEn)
        Me.tbpControl.Controls.Add(Me.cmbOvloThres)
        Me.tbpControl.Controls.Add(Me.lblOvloThres)
        Me.tbpControl.Controls.Add(Me.cmbOvloSel)
        Me.tbpControl.Controls.Add(Me.lblOvloSel)
        Me.tbpControl.Controls.Add(Me.cmbOvloRng)
        Me.tbpControl.Controls.Add(Me.lblOvloRng)
        Me.tbpControl.Location = New System.Drawing.Point(4, 28)
        Me.tbpControl.Margin = New System.Windows.Forms.Padding(4)
        Me.tbpControl.Name = "tbpControl"
        Me.tbpControl.Padding = New System.Windows.Forms.Padding(4)
        Me.tbpControl.Size = New System.Drawing.Size(509, 289)
        Me.tbpControl.TabIndex = 1
        Me.tbpControl.Text = "Control"
        '
        'btnCtrlRead
        '
        Me.btnCtrlRead.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnCtrlRead.Location = New System.Drawing.Point(329, 253)
        Me.btnCtrlRead.Name = "btnCtrlRead"
        Me.btnCtrlRead.Size = New System.Drawing.Size(83, 28)
        Me.btnCtrlRead.TabIndex = 55
        Me.btnCtrlRead.Text = "Read"
        Me.btnCtrlRead.UseVisualStyleBackColor = True
        '
        'btnCtrlSet
        '
        Me.btnCtrlSet.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnCtrlSet.Location = New System.Drawing.Point(418, 253)
        Me.btnCtrlSet.Name = "btnCtrlSet"
        Me.btnCtrlSet.Size = New System.Drawing.Size(83, 28)
        Me.btnCtrlSet.TabIndex = 54
        Me.btnCtrlSet.Text = "Set"
        Me.btnCtrlSet.UseVisualStyleBackColor = True
        '
        'chkDetectEn
        '
        Me.chkDetectEn.AutoSize = True
        Me.chkDetectEn.Location = New System.Drawing.Point(355, 39)
        Me.chkDetectEn.Margin = New System.Windows.Forms.Padding(4)
        Me.chkDetectEn.Name = "chkDetectEn"
        Me.chkDetectEn.Size = New System.Drawing.Size(92, 21)
        Me.chkDetectEn.TabIndex = 53
        Me.chkDetectEn.Text = "DETC_En"
        Me.chkDetectEn.UseVisualStyleBackColor = True
        '
        'lblVinTagRegVal
        '
        Me.lblVinTagRegVal.AutoSize = True
        Me.lblVinTagRegVal.Location = New System.Drawing.Point(430, 210)
        Me.lblVinTagRegVal.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblVinTagRegVal.Name = "lblVinTagRegVal"
        Me.lblVinTagRegVal.Size = New System.Drawing.Size(17, 17)
        Me.lblVinTagRegVal.TabIndex = 52
        Me.lblVinTagRegVal.Text = "V"
        '
        'trbVinTagReg
        '
        Me.trbVinTagReg.AutoSize = False
        Me.trbVinTagReg.Location = New System.Drawing.Point(150, 210)
        Me.trbVinTagReg.Margin = New System.Windows.Forms.Padding(4)
        Me.trbVinTagReg.Name = "trbVinTagReg"
        Me.trbVinTagReg.Size = New System.Drawing.Size(276, 31)
        Me.trbVinTagReg.TabIndex = 51
        '
        'lblVinTagReg
        '
        Me.lblVinTagReg.AutoSize = True
        Me.lblVinTagReg.Location = New System.Drawing.Point(12, 217)
        Me.lblVinTagReg.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblVinTagReg.Name = "lblVinTagReg"
        Me.lblVinTagReg.Size = New System.Drawing.Size(39, 17)
        Me.lblVinTagReg.TabIndex = 50
        Me.lblVinTagReg.Text = "TVIN"
        '
        'lblVinDutyReg
        '
        Me.lblVinDutyReg.AutoSize = True
        Me.lblVinDutyReg.Location = New System.Drawing.Point(13, 173)
        Me.lblVinDutyReg.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblVinDutyReg.Name = "lblVinDutyReg"
        Me.lblVinDutyReg.Size = New System.Drawing.Size(46, 17)
        Me.lblVinDutyReg.TabIndex = 47
        Me.lblVinDutyReg.Text = "DUTY"
        '
        'lblIsrcDetReg
        '
        Me.lblIsrcDetReg.AutoSize = True
        Me.lblIsrcDetReg.Location = New System.Drawing.Point(12, 141)
        Me.lblIsrcDetReg.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblIsrcDetReg.Name = "lblIsrcDetReg"
        Me.lblIsrcDetReg.Size = New System.Drawing.Size(45, 17)
        Me.lblIsrcDetReg.TabIndex = 44
        Me.lblIsrcDetReg.Text = "TDET"
        '
        'lblIsrcReg
        '
        Me.lblIsrcReg.AutoSize = True
        Me.lblIsrcReg.Location = New System.Drawing.Point(12, 110)
        Me.lblIsrcReg.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblIsrcReg.Name = "lblIsrcReg"
        Me.lblIsrcReg.Size = New System.Drawing.Size(79, 17)
        Me.lblIsrcReg.TabIndex = 16
        Me.lblIsrcReg.Text = "ISRC Value"
        '
        'chkVoutEn
        '
        Me.chkVoutEn.AutoSize = True
        Me.chkVoutEn.Location = New System.Drawing.Point(355, 10)
        Me.chkVoutEn.Margin = New System.Windows.Forms.Padding(4)
        Me.chkVoutEn.Name = "chkVoutEn"
        Me.chkVoutEn.Size = New System.Drawing.Size(80, 21)
        Me.chkVoutEn.TabIndex = 15
        Me.chkVoutEn.Text = "Vout En"
        Me.chkVoutEn.UseVisualStyleBackColor = True
        '
        'cmbOvloThres
        '
        Me.cmbOvloThres.FormattingEnabled = True
        Me.cmbOvloThres.Location = New System.Drawing.Point(160, 73)
        Me.cmbOvloThres.Margin = New System.Windows.Forms.Padding(4)
        Me.cmbOvloThres.Name = "cmbOvloThres"
        Me.cmbOvloThres.Size = New System.Drawing.Size(156, 24)
        Me.cmbOvloThres.TabIndex = 6
        '
        'lblOvloThres
        '
        Me.lblOvloThres.AutoSize = True
        Me.lblOvloThres.Location = New System.Drawing.Point(12, 78)
        Me.lblOvloThres.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblOvloThres.Name = "lblOvloThres"
        Me.lblOvloThres.Size = New System.Drawing.Size(100, 17)
        Me.lblOvloThres.TabIndex = 5
        Me.lblOvloThres.Text = "OV_Threshold"
        '
        'cmbOvloSel
        '
        Me.cmbOvloSel.FormattingEnabled = True
        Me.cmbOvloSel.Location = New System.Drawing.Point(160, 41)
        Me.cmbOvloSel.Margin = New System.Windows.Forms.Padding(4)
        Me.cmbOvloSel.Name = "cmbOvloSel"
        Me.cmbOvloSel.Size = New System.Drawing.Size(156, 24)
        Me.cmbOvloSel.TabIndex = 4
        '
        'lblOvloSel
        '
        Me.lblOvloSel.AutoSize = True
        Me.lblOvloSel.Location = New System.Drawing.Point(12, 44)
        Me.lblOvloSel.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblOvloSel.Name = "lblOvloSel"
        Me.lblOvloSel.Size = New System.Drawing.Size(62, 17)
        Me.lblOvloSel.TabIndex = 3
        Me.lblOvloSel.Text = "OV_SEL"
        '
        'cmbOvloRng
        '
        Me.cmbOvloRng.FormattingEnabled = True
        Me.cmbOvloRng.Location = New System.Drawing.Point(160, 7)
        Me.cmbOvloRng.Margin = New System.Windows.Forms.Padding(4)
        Me.cmbOvloRng.Name = "cmbOvloRng"
        Me.cmbOvloRng.Size = New System.Drawing.Size(156, 24)
        Me.cmbOvloRng.TabIndex = 2
        '
        'lblOvloRng
        '
        Me.lblOvloRng.AutoSize = True
        Me.lblOvloRng.Location = New System.Drawing.Point(12, 11)
        Me.lblOvloRng.Margin = New System.Windows.Forms.Padding(4, 0, 4, 0)
        Me.lblOvloRng.Name = "lblOvloRng"
        Me.lblOvloRng.Size = New System.Drawing.Size(86, 17)
        Me.lblOvloRng.TabIndex = 1
        Me.lblOvloRng.Text = "OVLO_RNG"
        '
        'Interrupt
        '
        Me.Interrupt.BackColor = System.Drawing.SystemColors.Control
        Me.Interrupt.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Interrupt.Controls.Add(Me.Label1)
        Me.Interrupt.Controls.Add(Me.btnReadInt)
        Me.Interrupt.Controls.Add(Me.btnSetInt)
        Me.Interrupt.Controls.Add(Me.chkOTMask)
        Me.Interrupt.Controls.Add(Me.chkOCMask)
        Me.Interrupt.Controls.Add(Me.chkOVMask)
        Me.Interrupt.Controls.Add(Me.chkSwitchOnMask)
        Me.Interrupt.Controls.Add(Me.chkTimerOutMask)
        Me.Interrupt.Controls.Add(Me.chkPwrOnMask)
        Me.Interrupt.Controls.Add(Me.chkOverTagMask)
        Me.Interrupt.Location = New System.Drawing.Point(4, 28)
        Me.Interrupt.Name = "Interrupt"
        Me.Interrupt.Padding = New System.Windows.Forms.Padding(3)
        Me.Interrupt.Size = New System.Drawing.Size(509, 289)
        Me.Interrupt.TabIndex = 2
        Me.Interrupt.Text = "Interrupt"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(14, 12)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(262, 17)
        Me.Label1.TabIndex = 58
        Me.Label1.Text = "Masked Interrupt will not trigger interrupt"
        '
        'btnReadInt
        '
        Me.btnReadInt.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnReadInt.Location = New System.Drawing.Point(329, 253)
        Me.btnReadInt.Name = "btnReadInt"
        Me.btnReadInt.Size = New System.Drawing.Size(83, 28)
        Me.btnReadInt.TabIndex = 57
        Me.btnReadInt.Text = "Read"
        Me.btnReadInt.UseVisualStyleBackColor = True
        '
        'btnSetInt
        '
        Me.btnSetInt.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.btnSetInt.Location = New System.Drawing.Point(418, 253)
        Me.btnSetInt.Name = "btnSetInt"
        Me.btnSetInt.Size = New System.Drawing.Size(83, 28)
        Me.btnSetInt.TabIndex = 56
        Me.btnSetInt.Text = "Set"
        Me.btnSetInt.UseVisualStyleBackColor = True
        '
        'chkOTMask
        '
        Me.chkOTMask.AutoSize = True
        Me.chkOTMask.Location = New System.Drawing.Point(17, 220)
        Me.chkOTMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkOTMask.Name = "chkOTMask"
        Me.chkOTMask.Size = New System.Drawing.Size(85, 21)
        Me.chkOTMask.TabIndex = 22
        Me.chkOTMask.Text = "OT_FLG"
        Me.chkOTMask.UseVisualStyleBackColor = True
        '
        'chkOCMask
        '
        Me.chkOCMask.AutoSize = True
        Me.chkOCMask.Location = New System.Drawing.Point(17, 191)
        Me.chkOCMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkOCMask.Name = "chkOCMask"
        Me.chkOCMask.Size = New System.Drawing.Size(85, 21)
        Me.chkOCMask.TabIndex = 21
        Me.chkOCMask.Text = "OC_FLG"
        Me.chkOCMask.UseVisualStyleBackColor = True
        '
        'chkOVMask
        '
        Me.chkOVMask.AutoSize = True
        Me.chkOVMask.Location = New System.Drawing.Point(17, 162)
        Me.chkOVMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkOVMask.Name = "chkOVMask"
        Me.chkOVMask.Size = New System.Drawing.Size(85, 21)
        Me.chkOVMask.TabIndex = 20
        Me.chkOVMask.Text = "OV_FLG"
        Me.chkOVMask.UseVisualStyleBackColor = True
        '
        'chkSwitchOnMask
        '
        Me.chkSwitchOnMask.AutoSize = True
        Me.chkSwitchOnMask.Location = New System.Drawing.Point(17, 133)
        Me.chkSwitchOnMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkSwitchOnMask.Name = "chkSwitchOnMask"
        Me.chkSwitchOnMask.Size = New System.Drawing.Size(110, 21)
        Me.chkSwitchOnMask.TabIndex = 19
        Me.chkSwitchOnMask.Text = "SWON_MSK"
        Me.chkSwitchOnMask.UseVisualStyleBackColor = True
        '
        'chkTimerOutMask
        '
        Me.chkTimerOutMask.AutoSize = True
        Me.chkTimerOutMask.Location = New System.Drawing.Point(17, 104)
        Me.chkTimerOutMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkTimerOutMask.Name = "chkTimerOutMask"
        Me.chkTimerOutMask.Size = New System.Drawing.Size(127, 21)
        Me.chkTimerOutMask.TabIndex = 18
        Me.chkTimerOutMask.Text = "TMROUT_MSK"
        Me.chkTimerOutMask.UseVisualStyleBackColor = True
        '
        'chkPwrOnMask
        '
        Me.chkPwrOnMask.AutoSize = True
        Me.chkPwrOnMask.Location = New System.Drawing.Point(17, 46)
        Me.chkPwrOnMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkPwrOnMask.Name = "chkPwrOnMask"
        Me.chkPwrOnMask.Size = New System.Drawing.Size(120, 21)
        Me.chkPwrOnMask.TabIndex = 17
        Me.chkPwrOnMask.Text = "PWRON_MSK"
        Me.chkPwrOnMask.UseVisualStyleBackColor = True
        '
        'chkOverTagMask
        '
        Me.chkOverTagMask.AutoSize = True
        Me.chkOverTagMask.Location = New System.Drawing.Point(17, 75)
        Me.chkOverTagMask.Margin = New System.Windows.Forms.Padding(4)
        Me.chkOverTagMask.Name = "chkOverTagMask"
        Me.chkOverTagMask.Size = New System.Drawing.Size(135, 21)
        Me.chkOverTagMask.TabIndex = 16
        Me.chkOverTagMask.Text = "OVERTAG_MSK"
        Me.chkOverTagMask.UseVisualStyleBackColor = True
        '
        'pnlRegisters
        '
        Me.pnlRegisters.Location = New System.Drawing.Point(1, 125)
        Me.pnlRegisters.Margin = New System.Windows.Forms.Padding(4)
        Me.pnlRegisters.Name = "pnlRegisters"
        Me.pnlRegisters.Size = New System.Drawing.Size(780, 443)
        Me.pnlRegisters.TabIndex = 29
        Me.pnlRegisters.Visible = False
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = Global.NX30P6093_MP22.My.Resources.Resources.NXP_logo_s
        Me.PictureBox1.Location = New System.Drawing.Point(628, 71)
        Me.PictureBox1.Margin = New System.Windows.Forms.Padding(4)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(133, 62)
        Me.PictureBox1.TabIndex = 28
        Me.PictureBox1.TabStop = False
        '
        'cmbIsrcVal
        '
        Me.cmbIsrcVal.FormattingEnabled = True
        Me.cmbIsrcVal.Location = New System.Drawing.Point(160, 107)
        Me.cmbIsrcVal.Margin = New System.Windows.Forms.Padding(4)
        Me.cmbIsrcVal.Name = "cmbIsrcVal"
        Me.cmbIsrcVal.Size = New System.Drawing.Size(156, 24)
        Me.cmbIsrcVal.TabIndex = 56
        '
        'cmbIsrcDet
        '
        Me.cmbIsrcDet.FormattingEnabled = True
        Me.cmbIsrcDet.Location = New System.Drawing.Point(160, 138)
        Me.cmbIsrcDet.Margin = New System.Windows.Forms.Padding(4)
        Me.cmbIsrcDet.Name = "cmbIsrcDet"
        Me.cmbIsrcDet.Size = New System.Drawing.Size(156, 24)
        Me.cmbIsrcDet.TabIndex = 57
        '
        'cmbVinDuty
        '
        Me.cmbVinDuty.FormattingEnabled = True
        Me.cmbVinDuty.Location = New System.Drawing.Point(160, 170)
        Me.cmbVinDuty.Margin = New System.Windows.Forms.Padding(4)
        Me.cmbVinDuty.Name = "cmbVinDuty"
        Me.cmbVinDuty.Size = New System.Drawing.Size(156, 24)
        Me.cmbVinDuty.TabIndex = 58
        '
        'frmMain_mp22
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(8.0!, 16.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(781, 593)
        Me.Controls.Add(Me.pnlFunctions)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.theToolbar)
        Me.Controls.Add(Me.grpDevice)
        Me.Controls.Add(Me.StatusStrip1)
        Me.Controls.Add(Me.TheMenu)
        Me.Controls.Add(Me.pnlRegisters)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MainMenuStrip = Me.TheMenu
        Me.Margin = New System.Windows.Forms.Padding(4)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "frmMain_mp22"
        Me.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide
        Me.Text = "NX30P6903(MP22)"
        Me.StatusStrip1.ResumeLayout(False)
        Me.StatusStrip1.PerformLayout()
        Me.grpDevice.ResumeLayout(False)
        Me.grpDevice.PerformLayout()
        Me.TheMenu.ResumeLayout(False)
        Me.TheMenu.PerformLayout()
        Me.theToolbar.ResumeLayout(False)
        Me.theToolbar.PerformLayout()
        Me.pnlFunctions.ResumeLayout(False)
        Me.GroupBox1.ResumeLayout(False)
        Me.grpRaised.ResumeLayout(False)
        Me.grpAdcChannels.ResumeLayout(False)
        Me.grpAdcChannels.PerformLayout()
        Me.TabControl2.ResumeLayout(False)
        Me.tbpControl.ResumeLayout(False)
        Me.tbpControl.PerformLayout()
        CType(Me.trbVinTagReg, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Interrupt.ResumeLayout(False)
        Me.Interrupt.PerformLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents StatusStrip1 As System.Windows.Forms.StatusStrip
    Friend WithEvents tslConnection As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents tmrWork As System.Windows.Forms.Timer
    Friend WithEvents tslInterface As System.Windows.Forms.ToolStripStatusLabel
    Friend WithEvents grpDevice As System.Windows.Forms.GroupBox
    Friend WithEvents lblRev As System.Windows.Forms.Label
    Friend WithEvents lblId As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents lblAddr As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents TheMenu As System.Windows.Forms.MenuStrip
    Friend WithEvents tsmView As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmFunctions As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmRegisters As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmIO As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmRead As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmWrite As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmHelp As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ToolStripSeparator1 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents tsmReset As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ToolStripSeparator2 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents tsmRefresh As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmInterval0 As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ToolStripSeparator3 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents tsmInterval1 As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmInterval2 As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmInterval4 As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmAbout As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents tsmManual As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents theToolbar As System.Windows.Forms.ToolStrip
    Friend WithEvents pnlFunctions As System.Windows.Forms.Panel
    Friend WithEvents grpAdcChannels As System.Windows.Forms.GroupBox
    Friend WithEvents txtVinAdc As System.Windows.Forms.TextBox
    Friend WithEvents TabControl2 As System.Windows.Forms.TabControl
    Friend WithEvents tbpControl As System.Windows.Forms.TabPage
    Friend WithEvents lblVinTagRegVal As System.Windows.Forms.Label
    Friend WithEvents trbVinTagReg As System.Windows.Forms.TrackBar
    Friend WithEvents lblVinTagReg As System.Windows.Forms.Label
    Friend WithEvents lblVinDutyReg As System.Windows.Forms.Label
    Friend WithEvents lblIsrcDetReg As System.Windows.Forms.Label
    Friend WithEvents lblIsrcReg As System.Windows.Forms.Label
    Friend WithEvents chkVoutEn As System.Windows.Forms.CheckBox
    Friend WithEvents cmbOvloThres As System.Windows.Forms.ComboBox
    Friend WithEvents lblOvloThres As System.Windows.Forms.Label
    Friend WithEvents cmbOvloSel As System.Windows.Forms.ComboBox
    Friend WithEvents lblOvloSel As System.Windows.Forms.Label
    Friend WithEvents cmbOvloRng As System.Windows.Forms.ComboBox
    Friend WithEvents lblOvloRng As System.Windows.Forms.Label
    Friend WithEvents tsbWrite As System.Windows.Forms.ToolStripButton
    Friend WithEvents tsbRead As System.Windows.Forms.ToolStripButton
    Friend WithEvents ToolStripSeparator4 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents tsbReset As System.Windows.Forms.ToolStripButton
    Friend WithEvents ToolStripSeparator5 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents tsbFunctions As System.Windows.Forms.ToolStripButton
    Friend WithEvents tsbRegisters As System.Windows.Forms.ToolStripButton
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents ToolStripSeparator6 As System.Windows.Forms.ToolStripSeparator
    Friend WithEvents tsbRefresh As System.Windows.Forms.ToolStripLabel
    Friend WithEvents tscRefresh As System.Windows.Forms.ToolStripComboBox
    Friend WithEvents pnlRegisters As System.Windows.Forms.Panel
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents chkSwitchOnSts As System.Windows.Forms.CheckBox
    Friend WithEvents chkTimeOutSts As System.Windows.Forms.CheckBox
    Friend WithEvents chkOverTagSts As System.Windows.Forms.CheckBox
    Friend WithEvents chkPwrOnSts As System.Windows.Forms.CheckBox
    Friend WithEvents grpRaised As System.Windows.Forms.GroupBox
    Friend WithEvents chkOTflag As System.Windows.Forms.CheckBox
    Friend WithEvents chkOCflag As System.Windows.Forms.CheckBox
    Friend WithEvents chkOVflag As System.Windows.Forms.CheckBox
    Friend WithEvents chkDetectEn As System.Windows.Forms.CheckBox
    Friend WithEvents btnCtrlRead As System.Windows.Forms.Button
    Friend WithEvents btnCtrlSet As System.Windows.Forms.Button
    Friend WithEvents Interrupt As System.Windows.Forms.TabPage
    Friend WithEvents btnReadInt As System.Windows.Forms.Button
    Friend WithEvents btnSetInt As System.Windows.Forms.Button
    Friend WithEvents chkOTMask As System.Windows.Forms.CheckBox
    Friend WithEvents chkOCMask As System.Windows.Forms.CheckBox
    Friend WithEvents chkOVMask As System.Windows.Forms.CheckBox
    Friend WithEvents chkSwitchOnMask As System.Windows.Forms.CheckBox
    Friend WithEvents chkTimerOutMask As System.Windows.Forms.CheckBox
    Friend WithEvents chkPwrOnMask As System.Windows.Forms.CheckBox
    Friend WithEvents chkOverTagMask As System.Windows.Forms.CheckBox
    Friend WithEvents lblVinAdc As System.Windows.Forms.Label
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents cmbVinDuty As System.Windows.Forms.ComboBox
    Friend WithEvents cmbIsrcDet As System.Windows.Forms.ComboBox
    Friend WithEvents cmbIsrcVal As System.Windows.Forms.ComboBox

End Class
