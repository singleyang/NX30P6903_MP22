Imports nx30p6903_mp22_fields

Public Class DataField

    Private m_dataFieldEnum As pca_data_fields_enum_t

    Public ReadOnly Property Caption As String
        Get
            'Todo: fix this mess. Complete BS
            Dim sz As UShort = &H400, buf(sz) As Byte
            nx30_mp22_import.pcaGetCaption_hidden(m_dataFieldEnum, buf, sz)
            Return ConvertToText(buf, sz)
        End Get
    End Property

    Public ReadOnly Property ValueCount As Integer
        Get
            Return nx30_mp22_import.pcaGetValueCount_hidden(m_dataFieldEnum)
        End Get
    End Property

    Public ReadOnly Property ValueText(index As Integer) As String
        Get
            Dim sz As UShort = &H400, buf(sz) As Byte
            If nx30_mp22_import.pcaGetValueText_hidden(m_dataFieldEnum, index, buf, sz) <> 0 Then
                Return ConvertToText(buf, sz)
            Else
                Return ""
            End If
        End Get
    End Property

    Public Property CurrentValue As Integer
        Get
            Return pcaGetCurrentValue_hidden(m_dataFieldEnum)
        End Get
        Set(value As Integer)
            pcaSetDataField_hidden(m_dataFieldEnum, value)
        End Set
    End Property

    Public Sub WriteCurrentValue()
        pcaWriteDataField_hidden(m_dataFieldEnum)
    End Sub

    Public ReadOnly Property CurrentValueText As String
        Get
            Dim sz As UShort = &H400, buf(sz) As Byte
            If pcaGetCurrentText_hidden(m_dataFieldEnum, buf, sz) <> 0 Then
                Return ConvertToText(buf, sz)
            Else
                Return ""
            End If
        End Get
    End Property

    Friend ReadOnly Property Field As pca_data_fields_enum_t
        Get
            Return m_dataFieldEnum
        End Get
    End Property

    Public ReadOnly Property IsReadOnly As Boolean
        Get
            Return pcaIsDataFieldReadOnly_hidden(m_dataFieldEnum) <> 0
        End Get
    End Property

    Public Sub New(Field As pca_data_fields_enum_t)
        m_dataFieldEnum = Field
    End Sub

End Class
