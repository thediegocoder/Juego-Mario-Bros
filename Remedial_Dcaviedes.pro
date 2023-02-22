QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = app


SOURCES += main.cpp \
    Bloques.cpp \
    Ducto.cpp \
    Fondo.cpp \
    Juego.cpp \
    Nivel.cpp \
    Enemy.cpp \
    Inert.cpp \
    Mario.cpp \
    Entity.cpp \
    Object.cpp

HEADERS  += \
    Bloques.h \
    Ducto.h \
    Fondo.h \
    Juego.h \
    Nivel.h \
    Enemy.h \
    Inert.h \
    Mario.h \
    Object.h \
    utils.h \
    Entity.h

RESOURCES += \
    recursos.qrc

    # Default rules for deployment.
    qnx: target.path = /tmp/$${TARGET}/bin
    else: unix:!android: target.path = /opt/$${TARGET}/bin
    !isEmpty(target.path): INSTALLS += target
