Imports nx30p6903_mp22_fields
Imports System.Runtime.InteropServices

Module Globals

    Private m_callback As pca_notify_function_t = Nothing

    Friend ReadOnly Property GetCallBack As pca_notify_function_t
        Get
            If m_callback = Nothing Then
                m_callback = New pca_notify_function_t(AddressOf OnNotify)
            End If
            Return m_callback
        End Get
    End Property


    Private Sub OnNotify(Field As pca_data_fields_enum_t, result As pca_notify_t)
        Model.OnNotify(Field, result)
    End Sub

End Module
