Imports System.Collections.ObjectModel
Imports nx30p6903_mp22_fields

Public Class Model

    Public Enum pca_result_t
        pca_ok
        pca_invalidIF
        pca_IFnotPresent
        pca_IFbusy
        pca_nosuchfunction
        pca_cantopenIF
        pca_badParam
        pca_readFailed
        pca_writeFailed
        pca_timedout
        pca_dataTooLarge
        pca_unknown
    End Enum

    Private Shared m_views As New Collection(Of View)
    Private Shared m_sla As Byte

    Public Shared Function ReadAll() As pca_result_t
        Return pcaReadAll_hidden()
    End Function

    Public Shared Function WriteAll() As pca_result_t
        Return pcaWriteAll_hidden()
    End Function

    Public Shared Function ReadRegister(regnumber As Integer) As pca_result_t
        Return pcaReadRegister_hidden(regnumber)
    End Function

    Public Shared Function ReadRegisters(regnumber As Integer, count As Integer) As pca_result_t
        Return pcaReadRegisters_hidden(regnumber, count)
    End Function

    Public Shared Property RegisterValue(RegNumber As Integer) As UInt16
        Get
            Return CUShort(pcaGetRegisterValue_hidden(RegNumber))
        End Get
        Set(value As UInt16)

        End Set
    End Property

    Public Shared ReadOnly Property Caption(Field As pca_data_fields_enum_t) As String
        Get
            Dim data As New DataField(Field)
            Return data.Caption
        End Get
    End Property

    Friend Shared Sub OnNotify(Field As pca_data_fields_enum_t, result As pca_notify_t)
        ' Find all instances of DataField
        If result = pca_notify_t.tr_ok Then
            For Each v As View In m_views
                If v.Field.Field = Field Then
                    v.DataChanged()
                    'Exit For
                End If
            Next
        Else
            'ToDo:
        End If
    End Sub

    Private Shared ReadOnly Property ViewExists(theView As View) As Boolean
        Get
            Return m_views.Contains(theView)
        End Get
    End Property

    Private Shared Sub RemoveView(v As View)
        m_views.Remove(v)
    End Sub

    Friend Shared Sub Register(v As View)
        If ViewExists(v) Then RemoveView(v)
        m_views.Add(v)
    End Sub

    Shared Sub New()
        pcaRegisterNotification_hidden(GetCallBack)
    End Sub

    Shared Property SlaveAddress As Byte
        Get
            Return m_sla
        End Get
        Set(value As Byte)
            m_sla = value
            pcaSlaveAddress_hidden(m_sla)
        End Set
    End Property

End Class
