# compilar con: makensis instalar.nsi
# Nombre del instalador final
OutFile "InstaladorPortafolio.exe"

# Carpeta de destino por defecto
InstallDir "$PROGRAMFILES\PortafolioIvanJRCH"

# Página de bienvenida e instalación
Page directory
Page instfiles

Section "Principal"
    SetOutPath "$INSTDIR"
    File "portafolio.exe"
    
    # Crear acceso directo
    CreateShortcut "$SMPROGRAMS\Portafolio IvanJRCH.lnk" "$INSTDIR\portafolio.exe"
    
    # Crear desinstalador
    WriteUninstaller "$INSTDIR\uninstall.exe"
SectionEnd

# Sección de desinstalación
Section "Uninstall"
    Delete "$INSTDIR\portafolio.exe"
    Delete "$INSTDIR\uninstall.exe"
    Delete "$SMPROGRAMS\Portafolio IvanJRCH.lnk"
    RMDir "$INSTDIR"
SectionEnd
