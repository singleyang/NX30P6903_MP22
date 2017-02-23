Imports System.Runtime.InteropServices
Imports nx30p6903_mp22_fields
Imports mvc.Model

Friend Module nx30_mp22_import

    Friend Const DLLname As String = "nx30p6903_mp22_def.dll"

    Friend Function ConvertToText(buf() As Byte, sz As Integer) As String
        Dim cnt As Integer = 1
        While buf(cnt) <> 0 AndAlso buf(cnt) <> &HA AndAlso buf(cnt) <> &HD AndAlso cnt <= sz
            cnt += 1
        End While
        ReDim Preserve buf(cnt - 1)
        Dim encoder As New Text.UTF7Encoding
        Return encoder.GetString(buf)
    End Function

    ' Returns the caption text of a data field, or NULL if none exists.
    <DllImportAttribute(DLLname, EntryPoint:="pcaGetCaption", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaGetCaption_hidden(dataField As pca_data_fields_enum_t, ByVal Vstr() As Byte, size As Integer) As pca_result_t
    End Function

    ' Returns the number of values the data field is comrpised of.
    <DllImportAttribute(DLLname, EntryPoint:="pcaGetValueCount", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaGetValueCount_hidden(dataField As pca_data_fields_enum_t) As Integer
    End Function

    ' Returns the text for a specific value for specified data field
    <DllImportAttribute(DLLname, EntryPoint:="pcaGetValueText", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaGetValueText_hidden(dataField As pca_data_fields_enum_t, index As Integer, ByVal Vstr() As Byte, size As Integer) As Integer
    End Function

    ' Returns the current value for a specific data field
    <DllImportAttribute(DLLname, EntryPoint:="pcaGetCurrentValue", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaGetCurrentValue_hidden(dataField As pca_data_fields_enum_t) As Integer
    End Function

    ' Returns the text for the current value of the specific data field
    <DllImportAttribute(DLLname, EntryPoint:="pcaGetCurrentText", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaGetCurrentText_hidden(dataField As pca_data_fields_enum_t, ByVal Vstr() As Byte, size As Integer) As Integer
    End Function

    'Returns the value for a specific register
    <DllImportAttribute(DLLname, EntryPoint:="pcaGetRegisterValue", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaGetRegisterValue_hidden(RegNumber As Integer) As Integer
    End Function

    ' Register a call-back function to receive notofications of changes in the model
    <DllImportAttribute(DLLname, EntryPoint:="pcaRegisterNotification", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Sub pcaRegisterNotification_hidden(callback As pca_notify_function_t)
    End Sub

    ' Unregister a call-back function, to stop receiving notifications
    <DllImportAttribute(DLLname, EntryPoint:="pcaUnregisterNotification", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Sub pcaUnregisterNotification_hidden(callback As pca_notify_function_t)
    End Sub

    ' Reads the page where <dataField> belongs to. For each change in data fields, all call-back's will be called.
    <DllImportAttribute(DLLname, EntryPoint:="pcaReadDataField", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaReadDataField_hidden(dataField As pca_data_fields_enum_t) As pca_result_t
    End Function

    ' Reads a page. For each change in data fields, all call-back's will be called.
    <DllImportAttribute(DLLname, EntryPoint:="pcaReadRegister", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaReadRegister_hidden(RegNumber As Integer) As pca_result_t
    End Function

    ' Reads all pages. For each change in data fields, all call-back's will be called.
    <DllImportAttribute(DLLname, EntryPoint:="pcaReadAll", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaReadAll_hidden() As pca_result_t
    End Function

    ' Change the current value for the specified data field
    <DllImportAttribute(DLLname, EntryPoint:="pcaSetDataField", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaSetDataField_hidden(DataField As pca_data_fields_enum_t, value As Integer) As pca_result_t
    End Function

    ' Change the value for the specified page
    <DllImportAttribute(DLLname, EntryPoint:="pcaSetRegister", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Sub pcaSetRegister_hidden(RegNumber As Integer)
    End Sub

    ' Write the page containing the data field to the device
    <DllImportAttribute(DLLname, EntryPoint:="pcaWriteDataField", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaWriteDataField_hidden(DataField As pca_data_fields_enum_t) As pca_result_t
    End Function

    ' Write the specified page to the device
    <DllImportAttribute(DLLname, EntryPoint:="pcaWriteRegister", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaWriteRegister_hidden(RegNumber As Integer) As pca_result_t
    End Function

    ' Write all pages to the device
    <DllImportAttribute(DLLname, EntryPoint:="pcaWriteAll", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaWriteAll_hidden() As pca_result_t
    End Function

    ' Update and write the page containing the data field to the device
    <DllImportAttribute(DLLname, EntryPoint:="pcaSetAndWriteDataField", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaSetAndWriteDataField_hidden(DataField As pca_data_fields_enum_t, value As Integer) As pca_result_t
    End Function

    ' Write the page containing the data field to the device
    <DllImportAttribute(DLLname, EntryPoint:="pcaSetAndWriteRegister", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaSetAndWriteRegister_hidden(RegNumber As Integer, value As Integer) As pca_result_t
    End Function

    'Set the device's I2C slave address
    <DllImportAttribute(DLLname, EntryPoint:="pcaSlaveAddress", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Sub pcaSlaveAddress_hidden(sla As Integer)
    End Sub

    ' Returns zero if the datafield is writable
    <DllImportAttribute(DLLname, EntryPoint:="pcaIsRegisterReadOnly", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaIsRegisterReadOnly_hidden(regNumber As Integer) As Integer
    End Function

    ' Returns zero if the datafield is writable
    <DllImportAttribute(DLLname, EntryPoint:="pcaIsDataFieldReadOnly", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaIsDataFieldReadOnly_hidden(dataField As pca_data_fields_enum_t) As Integer
    End Function

    'Reads <count> registers starting at <regNumber>'s offset
    <DllImportAttribute(DLLname, EntryPoint:="pcaReadRegisters", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pcaReadRegisters_hidden(RegNumber As Integer, count As Integer) As pca_result_t
    End Function

End Module
