Imports System.Runtime.InteropServices
Imports PcaConnect.Connection

Module import

    Private Const dllname As String = "pca9498_com.dll"

    'Interface selection
    
    <DllImportAttribute(dllname, EntryPoint:="pc_selectInterface", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_selectInterface_hidden(ByVal interface_id As UInt32) As pc_result_t
    End Function

    <DllImportAttribute(dllname, EntryPoint:="pc_selectedInterface", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_selectedInterface_hidden(ByRef interface_id As UInt32) As pc_result_t
    End Function

    ' Initialisation
    <DllImportAttribute(dllname, EntryPoint:="pc_claim", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_claim_hidden() As pc_result_t
    End Function

    <DllImportAttribute(dllname, EntryPoint:="pc_release", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_release_hidden() As pc_result_t
    End Function

    <DllImportAttribute(dllname, EntryPoint:="pc_init", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_init_hidden() As pc_result_t
    End Function

    <DllImportAttribute(dllname, EntryPoint:="pc_info", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_info_hidden(ByVal str As Byte(), ByVal size As UInt64) As pc_result_t
    End Function

    <DllImportAttribute(dllname, EntryPoint:="pc_connected", SetLastError:=False, CharSet:=CharSet.Unicode, ExactSpelling:=True, CallingConvention:=CallingConvention.Cdecl)>
    Friend Function pc_connected_hidden() As pc_result_t
    End Function

End Module
