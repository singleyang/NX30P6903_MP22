Imports System.Collections.ObjectModel
Imports System.Runtime.InteropServices
Imports System.Text

Public Class Connection

    Public Enum pc_result_t
        pc_ok
        pc_invalidIF
        pc_IFnotPresent
        pc_IFbusy
        pc_nosuchfunction
        pc_cantopenIF
        pc_badParam
        pc_readFailed
        pc_writeFailed
        pc_timedout
        pc_dataTooLarge
        pc_unknown
    End Enum

    Private Shared currentIF_ID As UInt32 = 0

    Friend Shared Function ConvertToText(buf() As Byte, sz As Integer) As String
        Dim cnt As Integer = 0
        While buf(cnt) <> 0 AndAlso buf(cnt) <> &HA AndAlso buf(cnt) <> &HD AndAlso cnt <= sz
            cnt += 1
        End While
        ReDim Preserve buf(cnt - 1)
        Dim encoder As New Text.UTF7Encoding
        Return encoder.GetString(buf)
    End Function

    Public Shared Function SelectInterface(ID As UInt32) As pc_result_t
        If currentIF_ID > 0 Then Release()
        Dim result As pc_result_t = pc_selectInterface_hidden(ID)
        If result = pc_result_t.pc_ok Then currentIF_ID = ID
        If result = pc_result_t.pc_ok Then result = pc_claim_hidden()
        If result = pc_result_t.pc_ok Then result = pc_init_hidden()
        Return result
    End Function

    Public Shared ReadOnly Property SelectedInterface As UInt32
        Get
            Return currentIF_ID
        End Get
    End Property

    Public Shared ReadOnly Property Info As String
        Get
            Const size As Integer = 200
            Dim str(size) As Byte
            Dim result As pc_result_t = pc_info_hidden(str, size)
            Dim ret As String = ""
            If result = pc_result_t.pc_ok Then
                ret = ConvertToText(str, size)
            End If
            Return ret
        End Get
    End Property

    Public Shared ReadOnly Property Connected As Boolean
        Get
            Return pc_connected_hidden() = pc_result_t.pc_ok
        End Get
    End Property

    Public Shared Sub Release()
        pc_release_hidden()
        currentIF_ID = 0
    End Sub

    Shared Sub New()
        import.pc_init_hidden()
    End Sub

    Protected Overrides Sub Finalize()
        MyBase.Finalize()
        Release()
    End Sub

End Class
