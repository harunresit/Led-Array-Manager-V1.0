QT       += core gui

QT += widgets
qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Modules/Processes/Graphical/Sources/led.cpp \
    Modules/Processes/Graphical/Sources/view.cpp \
    Modules/Screens/Sources/animationtimeslidersetting.cpp \
    main.cpp \
    Modules/Processes/Graphical/Sources/draw.cpp \
    Modules/Processes/File/Sources/save.cpp \
    Modules/Screens/Sources/mainwindow.cpp \
    Modules/Screens/Sources/newsketch_screen.cpp \
    Modules/Screens/Sources/animationrgb.cpp

HEADERS += \
    Modules/Processes/File/Headers/config.h \
    Modules/Processes/Graphical/Headers/draw.h \
    Modules/Processes/File/Headers/save.h \
    Modules/Processes/Graphical/Headers/led.h \
    Modules/Processes/Graphical/Headers/view.h \
    Modules/Screens/Headers/animationrgb.h \
    Modules/Screens/Headers/mainwindow.h \
    Modules/Screens/Headers/newsketch_screen.h \
    Modules/Screens/Headers/animationtimeslidersetting.h

FORMS += \
    Modules/Screens/animationrgb.ui \
    Modules/Screens/animationtimeslidersetting.ui \
    Modules/Screens/mainwindow.ui \
    Modules/Screens/newsketch_screen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
