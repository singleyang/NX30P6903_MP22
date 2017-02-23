SetCompressor /SOLID lzma

!include Library.nsh
!include "WordFunc.nsh"
!include MUI2.nsh

!define MUI_ICON "Logo.ico"
!define MUI_HEADERIMAGE 
!define MUI_HEADERIMAGE_BITMAP "Logo.bmp"
!define MUI_HEADERIMAGE_RIGHT
!define MUI_INSTFILESPAGE_COLORS /windows

!define MUI_WELCOMEPAGE_TITLE "Welcome to the PCA949x installation wizard"
!define MUI_WELCOMEPAGE_TITLE_3LINES "PCA949x evaluation utility"
!define MUI_WELCOMEPAGE_TEXT "The PCA949x utility controls and monitors PCA949x boards for evaluation and demonstration purposes. This program will install the PCA949x utility, its libraries and drivers.$\n$\nPrevious versions will be uninstalled first.$\n$\nAdministrator rights are required."

!define MUI_LICENSEPAGE_TEXT_TOP "License Agreement"

!define MUI_WELCOMEFINISHPAGE_BITMAP "FrontPageLogo.bmp"
!define MUI_WELCOMEFINISHPAGE_NOSTRETCH

!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_FINISHPAGE_RUN $INSTDIR\PCA949x.exe
!define MUI_FINISHPAGE_RUN_TEXT "Launch PCA949x when this installation wizard closes"
!define MUI_FINISHPAGE_RUN_PARAMETERS ""

!define MUI_UNCONFIRMPAGE_TEXT_TOP "You are about to uninstall the PCA949x utility from your system. Press Uninstall if you want to continue."
!define MUI_UNCONFIRMPAGE_TEXT_LOCATION "Uninstaller"


!define MUI_ABORTWARNING

  
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE LicenseAgreement.rtf
!insertmacro MUI_PAGE_DIRECTORY

!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH


!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

!define localpath "..\bin\x64\Release"
 

!macro GetVersionLocal file basedef
!verbose push
!verbose 1
!tempfile _GetVersionLocal_nsi
!tempfile _GetVersionLocal_exe
!appendfile "${_GetVersionLocal_nsi}" 'Outfile "${_GetVersionLocal_exe}"$\nRequestexecutionlevel user$\n'
!appendfile "${_GetVersionLocal_nsi}" 'Section$\n!define D "$"$\n!define N "${D}\n"$\n'
!appendfile "${_GetVersionLocal_nsi}" 'GetDLLVersion "${file}" $2 $4$\n'
!appendfile "${_GetVersionLocal_nsi}" 'IntOp $1 $2 / 0x00010000$\nIntOp $2 $2 & 0x0000FFFF$\n'
!appendfile "${_GetVersionLocal_nsi}" 'IntOp $3 $4 / 0x00010000$\nIntOp $4 $4 & 0x0000FFFF$\n'
!appendfile "${_GetVersionLocal_nsi}" 'FileOpen $0 "${_GetVersionLocal_nsi}" w$\nStrCpy $9 "${N}"$\n'
!appendfile "${_GetVersionLocal_nsi}" 'FileWrite $0 "!define ${basedef}1 $1$9"$\nFileWrite $0 "!define ${basedef}2 $2$9"$\n'
!appendfile "${_GetVersionLocal_nsi}" 'FileWrite $0 "!define ${basedef}3 $3$9"$\nFileWrite $0 "!define ${basedef}4 $4$9"$\n'
!appendfile "${_GetVersionLocal_nsi}" 'FileClose $0$\nSectionend$\n'
!system '"${NSISDIR}\makensis" -NOCD -NOCONFIG "${_GetVersionLocal_nsi}"' = 0
!system '"${_GetVersionLocal_exe}" /S' = 0
!delfile "${_GetVersionLocal_exe}"
!undef _GetVersionLocal_exe
!include "${_GetVersionLocal_nsi}"
!delfile "${_GetVersionLocal_nsi}"
!undef _GetVersionLocal_nsi
!verbose pop
!macroend

!insertmacro GetVersionLocal "${localpath}\PCA949x.exe" pca_version
!define Vmajor "${pca_version1}"
!define Vminor "${pca_version2}"
!define Vrevision "${pca_version3}"
!define Vbuild "${pca_version4}"

!define VrequiredDotNet "4.0"
!define Company "NXP Semiconductors"
!define Suite "PCA949x"
!define localAppData "$APPDATA\${Company}\${Suite}\${Vmajor}.${Vminor}"

Name "${Suite}"
InstallDir "$PROGRAMFILES\${Company}\${Suite}"
RequestExecutionLevel admin
Var PreviousVersion

VIAddVersionKey /LANG=${LANG_ENGLISH} "ProductName" "${Suite}"
VIAddVersionKey /LANG=${LANG_ENGLISH} "Comments" "PCA949x evaluation software"
VIAddVersionKey /LANG=${LANG_ENGLISH} "CompanyName" "${Company}"
VIAddVersionKey /LANG=${LANG_ENGLISH} "LegalTrademarks" ""
VIAddVersionKey /LANG=${LANG_ENGLISH} "LegalCopyright" "© 2016, ${Company}"
VIAddVersionKey /LANG=${LANG_ENGLISH} "FileDescription" "${Suite} installer"
VIAddVersionKey /LANG=${LANG_ENGLISH} "FileVersion" "${Vmajor}.${Vminor}.${Vbuild}.${Vrevision}"
VIAddVersionKey /LANG=${LANG_ENGLISH} "ProductVersion" "${Vmajor}.${Vminor}.${Vbuild}.${Vrevision}"

VIProductVersion "${Vmajor}.${Vminor}.${Vbuild}.${Vrevision}"

OutFile "Install_${Suite}_${Vmajor}_${Vminor}_${Vbuild}.exe"
  
  
   
;--------------------------------------------------
; Do some initialization of varaibles
; Uninstaller location of previous version

Function .onInit
   ; Get uninstaller path for previous installations
   ReadRegStr $PreviousVersion HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "InstallLocation" 
FunctionEnd



;--------------------------------------------------
; Makes sure only one installer can run at a time

Function RunOnce
   System::Call 'kernel32::CreateMutexA(i 0, i 0, t "${Suite}Installer") i .r1 ?e'
   Pop $R0
    
   StrCmp $R0 0 +3
      MessageBox MB_OK|MB_ICONEXCLAMATION "The ${Suite} installer is already running."
  Abort
FunctionEnd



;--------------------------------------------------
;Gets the file version of mscoree.dll

Function GetDotNETVersion
  Push $0
  Push $1
 
  GetDLLVersion '$SYSDIR\mscoree.dll' $R0 $R1
  IfErrors version_error
  Goto version_string
  
  version_error:
     StrCpy $0 "not found"
     Goto version_done
 
  version_string:
     IntOp $R2 $R0 / 0x00010000
     IntOp $R3 $R0 & 0x0000FFFF
     StrCpy $0 "$R2.$R3"

   version_done:
      Pop $1
      Exch $0
FunctionEnd



;--------------------------------------------------
; Compares the dotNet version withe the required version
; Aborts the installer when the requirement isn't met
; User is advised to install the required version if necessary

Function CheckDotNet
   Call GetDotNETVersion
   Pop $0 
   DetailPrint 'Required .Net framework version: ${VrequiredDotNet}'
   DetailPrint 'Installed .Net framework version: $0'
    
   StrCmp $0 "not found" not_found check_version
 
   not_found:
   	;The user needs to install .Net v4 
   	;Show this requirement and abort the wizard
      	Goto check_need_download
        
   check_version:
    	${VersionCompare} $0 '${VrequiredDotNet}' $1
	IntCmp $1 2 check_need_download check_done check_done
	   
   check_need_download:
   	MessageBox MB_OK|MB_ICONSTOP "${Suite} requires Microsoft .Net Framework ${VrequiredDotNet} Client Profile.$\r$\nPlease visit http://www.microsoft.com and download Microsoft .NET Framework ${VrequiredDotNet} (Client Profile).$\nThe ${Suite} installation wizard will close now"
	Abort
	
   check_done:
FunctionEnd




;--------------------------------------------------
; If a previous installation exists, it is uninstalled

Function UninstallPreviousVersion
    StrLen $0 $PreviousVersion
    IntCmp $0 0 0 +2 +2
    Return
    DetailPrint "Uinstalling previous installation of ${Suite}"
    SetDetailsPrint none
    ;The next line ensures the uninstaller doesn't copy itself
    ExecWait '"$PreviousVersion\Uninstall.exe" /S _?=$PreviousVersion'
    ;Call it again, with auto copy. This time, the installer only deletes itself.
    ;ExecWait '"$PreviousVersion\Uninstall.exe" /S'
    Delete "$PreviousVersion\install.log "
    Delete "$PreviousVersion\Uninstall.exe "
    RMDir /r "$PreviousVersion"
    SetDetailsPrint both
 FunctionEnd



;--------------------------------------------------
; Dump the contents of the details window to file

!define LVM_GETITEMCOUNT 0x1004
!define LVM_GETITEMTEXT 0x102D

Function DumpLog
  Exch $5
  Push $0
  Push $1
  Push $2
  Push $3
  Push $4
  Push $6

  FindWindow $0 "#32770" "" $HWNDPARENT
  GetDlgItem $0 $0 1016
  StrCmp $0 0 error
  FileOpen $5 $5 "w"
  StrCmp $5 0 error
    SendMessage $0 ${LVM_GETITEMCOUNT} 0 0 $6
    System::Alloc ${NSIS_MAX_STRLEN}
    Pop $3
    StrCpy $2 0
    System::Call "*(i, i, i, i, i, i, i, i, i) i \
      (0, 0, 0, 0, 0, r3, ${NSIS_MAX_STRLEN}) .r1"
    loop: StrCmp $2 $6 done
      System::Call "User32::SendMessageA(i, i, i, i) i \
        ($0, ${LVM_GETITEMTEXT}, $2, r1)"
      System::Call "*$3(&t${NSIS_MAX_STRLEN} .r4)"
      FileWrite $5 "$4$\r$\n"
      IntOp $2 $2 + 1
      Goto loop
    done:
      FileClose $5
      System::Free $1
      System::Free $3
      Goto exit
  error:
    MessageBox MB_OK error
  exit:
    Pop $6
    Pop $4
    Pop $3
    Pop $2
    Pop $1
    Pop $0
    Exch $5
FunctionEnd


;--------------------------------------------------
; Installer

Section Install 
  SetOverwrite ifnewer
   
  Call RunOnce
  Call CheckDotNet
  Call UninstallPreviousVersion

  DetailPrint "Installing application and libraries"
  
  !define LIBRARY_X64
  
  SetOutPath "$INSTDIR"
  SetOverwrite on
  AllowSkipFiles off
   
  DetailPrint "PCA949x.exe"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\PCA949x.exe $INSTDIR\PCA949x.exe $INSTDIR
  DetailPrint "pca9498_def.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\pca9498_def.dll $INSTDIR\pca9498_def.dll $INSTDIR
  DetailPrint "pca9498_fields.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\pca9498_fields.dll $INSTDIR\pca9498_fields.dll $INSTDIR
  DetailPrint "mvc.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\mvc.dll $INSTDIR\mvc.dll $INSTDIR
  DetailPrint "pca9498_com.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\pca9498_com.dll $INSTDIR\pca9498_com.dll $INSTDIR
  DetailPrint "PcaConnect.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\PcaConnect.dll $INSTDIR\PcaConnect.dll $INSTDIR
  DetailPrint "libMPSSE-I2C.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED ${localpath}\libMPSSE-I2C.dll $INSTDIR\libMPSSE-I2C.dll $INSTDIR
  DetailPrint "aardvark.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED "Aardvark_dll\aardvark.dll" $INSTDIR\aardvark.dll $INSTDIR
  DetailPrint "ftd2xx.dll"
  !insertmacro InstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED "FTDI_dll\ftd2xx.dll" $INSTDIR\ftd2xx.dll $INSTDIR
  
  DetailPrint "Copy FTDI driver package"
  SetOutPath "$INSTDIR\FTDI driver" 
  File /r "FTDI driver\*.*"
  File "dpinst.exe"
  DetailPrint "Install FTDI driver."
  SetDetailsPrint none
  ExecWait '"$INSTDIR\FTDI driver\dpinst.exe"'
  Delete "$INSTDIR\FTDI driver\dpinst.exe"
  Delete "$INSTDIR\FTDI driver\dpinst.xml"
  Delete "$INSTDIR\FTDI driver\Logo.bmp"
  Delete "$INSTDIR\FTDI driver\logo.ico"
  Delete "$INSTDIR\FTDI driver\C232HM.bmp"
  SetDetailsPrint both
  
  DetailPrint "Adding shortcuts to Start Menu"
  CreateDirectory "$SMPROGRAMS\${Company}\${Suite}"
  CreateShortCut "$SMPROGRAMS\${Company}\${Suite}\PCA949x.lnk" "$INSTDIR\PCA949x.exe" "" "" "" SW_SHOWNORMAL "" "Teo"
    
  DetailPrint "Writing uninstall info"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "DisplayName" "${Suite}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "UninstallString" "$INSTDIR\Uninstall.exe"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "InstallLocation" "$INSTDIR"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "Publisher" "NXP Semiconductors"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "Contact" "NXP Semiconductors, San Jose, BL SiP"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "InstallSource" $EXEDIR
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "DisplayVersion" "${Vmajor}.${Vminor}.${Vbuild}.${Vrevision}"
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "EstimatedSize" 4030
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "VersionMajor" Vmajor
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "VersionMinor" Vminor
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}" "NoRepair" 1
  
  DetailPrint "Write the uninstaller"
  WriteUninstaller "$INSTDIR\uninstall.exe"
  
  IfRebootFlag 0 noreboot
    MessageBox MB_YESNO "A reboot is required to finish the installation. Do you wish to reboot now?" IDNO noreboot
      Reboot
  noreboot:
 
  Push $INSTDIR\install.log
  Call DumpLog

 
SectionEnd

Section uninstall

  DetailPrint "Removing application and libraries"
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\PCA949x.exe
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\mvc.dll
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\pca9498_def.dll
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\pca9498_com.dll
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\PcaConnect.dll
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\aardvark.dll
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED $INSTDIR\pca9498_fields.dll
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED "$INSTDIR\ftd2xx.dll"
  !insertmacro UninstallLib DLL NOTSHARED NOREBOOT_NOTPROTECTED "$INSTDIR\libMPSSE-I2C.dll"
  
  DetailPrint "Removing shortcuts from Start Menu"
  Delete "$SMPROGRAMS\${Company}\${Suite}\Teo.lnk"
  RMDir /r "$SMPROGRAMS\${Company}\${Suite}"
 
  Delete "$INSTDIR\install.log"
  Delete "$INSTDIR\Uninstall.exe"
  RMDir /r "$INSTDIR"
  DeleteRegKey HKLM "SOFTWARE\${Company}\${Suite}"
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${Suite}"
 
  IfRebootFlag 0 noreboot
      MessageBox MB_YESNO "A reboot is required to finish the installation. Do you wish to reboot now?" IDNO noreboot
        Reboot
    noreboot:
 
SectionEnd
