QT = widgets sql
TARGET = medocs
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp aboutdialog.cpp
HEADERS += mainwindow.h aboutdialog.h
FORMS += mainwindow.ui aboutdialog.ui
RESOURCES += medocs.qrc
win32 {
	RC_FILE = windows/windows.rc
}

unix:!macx {
	target.path = /opt/medocs/
	icon.files = linux/medocs.png
	icon.path = /usr/share/pixmaps/
	shortcutfile.files += linux/medocs.desktop
	shortcutfile.path = /usr/share/applications/
    base.files = ../base/dpm.db
    base.path = /opt/medocs/
    lncreate.path = /usr/bin
    lncreate.target = medocs
    lncreate.commands = @ln -s /opt/medocs/medocs /usr/bin/medocs
    lncreate.uninstall = @rm /usr/bin/medocs
	INSTALLS += target
	INSTALLS += icon
	INSTALLS += shortcutfile
	INSTALLS += base
	INSTALLS += lncreate
}

macx: {
	ICON = macx/medocs.icns
}
