QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    config.cpp \
    dialog.cpp \
    entry.cpp \
    main.cpp \
    mainwindow.cpp \
    display.cpp \
    pkg_info.cpp \
    pkg_note.cpp \
    pm/cb.cpp \
    pm/conf.cpp \
    pm/util.cpp \
    pm/parse.cpp \
    pm/debug.cpp \
    pm/interface.cpp \

HEADERS += \
    config.h \
    dialog.h \
    entry.h \
    mainwindow.h \
    display.h \
    pkg_info.h \
    pkg_note.h \
    pm/cb.h \
    pm/conf.h \
    pm/util.h \
    pm/parse.h \
    pm/debug.h \
    pm/interface.h \
    

FORMS += \
    config.ui \
    dialog.ui \
    entry.ui \
    mainwindow.ui \
    pkg_info.ui \
    pkg_note.ui

TRANSLATIONS += \

LIBS += \
    /lib/libalpm.so

INCLUDEPATH += \

QMAKE_CFLAGS += \
        -g\
        -DSEARCH_LOCAL_WITH_HASH
QMAKE_CXXFLAGS += \
        -g\
        -DSEARCH_LOCAL_WITH_HASH
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
