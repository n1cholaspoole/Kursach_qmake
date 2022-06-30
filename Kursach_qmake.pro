QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addinfowindow.cpp \
    changeinfowindow.cpp \
    main.cpp \
    mainwindow.cpp \
    removeinfowindow.cpp \
    showinfowindow.cpp

HEADERS += \
    addinfowindow.h \
    changeinfowindow.h \
    mainwindow.h \
    removeinfowindow.h \
    showinfowindow.h

FORMS += \
    addinfowindow.ui \
    changeinfowindow.ui \
    mainwindow.ui \
    removeinfowindow.ui \
    showinfowindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data.txt

win32 {
        RC_FILE += Kursach_qmake.rc
        OTHER_FILES += Kursach_qmake.rc
}
