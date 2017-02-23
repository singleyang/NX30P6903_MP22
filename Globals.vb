Module Globals

    Public MainWindow As frmMain_mp22

    Friend Function TimeTicks() As Int64
        Return CLng(uSeconds() / 1000)
    End Function

    Friend Function uSeconds() As Int64
        Static start As Long = Now.Ticks
        Return CLng((Now.Ticks - start) / 10)
    End Function
End Module
