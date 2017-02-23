Imports nx30p6903_mp22_fields
Imports System.Runtime.InteropServices

Module nx30_mp22_types

    ' Result codes 
    Enum pca_notify_t
        tr_ok
        tr_badparam
        tr_ioerror
        tr_disconnect
        tr_connect
        tr_noconnection
    End Enum

    <UnmanagedFunctionPointer(CallingConvention.Cdecl)> Delegate Sub pca_notify_function_t(updatedField As pca_data_fields_enum_t, result As pca_notify_t)

End Module
