QT       += core gui
QT       += multimedia

QMAKE_LFLAGS +=-static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attack.cpp \
    caracter.cpp \
    fighter.cpp \
    main.cpp \
    menu.cpp \
    playground.cpp \
    widget.cpp

HEADERS += \
    AttackType.h \
    FighterStates.h \
    attack.h \
    caracter.h \
    fighter.h \
    menu.h \
    playground.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
