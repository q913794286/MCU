QT += core
QT -= gui

CONFIG += c++11

TARGET = stc15_DTU
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    app/main.c \
    app/sys_clock.c \
    app/service/app/function.c \
    stclib/USART1.C \
    stclib/delay.c \
    stclib/eeprom.c \
    stclib/GPIO.c \
    stclib/stc_timer.c \
    stclib/exit.c \
    stclib/spi.c \
    app/service/AES128/aes.c \
    app/service/AES128/aes128app.c

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    config.h \
    stdint.h \
    app/sys_clock.h \
    app/service/app/function.h \
    stclib/delay.h \
    stclib/eeprom.h \
    stclib/GPIO.h \
    stclib/stc_timer.h \
    stclib/STC15Fxxxx.H \
    stclib/USART1.h \
    list/delay.lst \
    list/eeprom.lst \
    list/exit.lst \
    list/function.lst \
    list/GPIO.lst \
    list/main.lst \
    list/relay.lst \
    list/spi.lst \
    list/stc_timer.lst \
    list/sys_clock.lst \
    list/USART1.lst \
    stclib/exit.h \
    stclib/spi.h \
    app/service/AES128/aes.h \
    app/service/AES128/aes128app.h

DISTFILES += \
    list/uip \
    list/uip.plg \
    list/function.__i \
    list/uip.hex \
    list/uip.lnp \
    list/uip.m51 \
    project.uvopt \
    project.uvproj
