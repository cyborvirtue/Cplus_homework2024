#-------------------------------------------------
#
# Project created by QtCreator 2022-04-29T18:08:55
#
#-------------------------------------------------

QT       += core gui

QT       += multimedia
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Road to football King
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        grown.cpp \
        main.cpp \
        racemode.cpp \
        selectionmode.cpp \
        succeq.cpp \
        successful.cpp \
        succezha.cpp \
        twinkle.cpp


HEADERS += \
        food.h \
        grown.h \
        racemode.h \
        selectionmode.h \
        succeq.h \
        successful.h \
        succezha.h \
        twinkle.h


FORMS += \
        grown.ui \
        grown.ui \
        racemode.ui \
        selectionmode.ui \
        succeq.ui \
        successful.ui \
        succezha.ui \
        twinkle.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    bgm.qrc \
    image.qrc

DISTFILES += \
    MotivationalMode /WechatIMG494.jpeg \
    MotivationalMode /WechatIMG496.jpeg \
    MotivationalMode /WechatIMG497.jpeg \
    MotivationalMode /WechatIMG498.jpeg \
    MotivationalMode /WechatIMG499.jpeg \
    MotivationalMode /WechatIMG500.jpeg \
    MotivationalMode /WechatIMG501.jpeg \
    MotivationalMode /WechatIMG502.jpeg \
    隐形的翅膀.wav
