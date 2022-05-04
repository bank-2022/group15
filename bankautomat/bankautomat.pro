QT       += core gui
QT +=network
QT +=serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lopetus.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp \
    nosta_rahaa.cpp \
    tili_saldo.cpp \
    tilitapahtumat.cpp \
    tunnusluku.cpp \
    valikko.cpp

HEADERS += \
    lopetus.h \
    mainwindow.h \
    myurl.h \
    nosta_rahaa.h \
    tili_saldo.h \
    tilitapahtumat.h \
    tunnusluku.h \
    valikko.h

FORMS += \
    lopetus.ui \
    mainwindow.ui \
    nosta_rahaa.ui \
    tili_saldo.ui \
    tilitapahtumat.ui \
    tunnusluku.ui \
    valikko.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../rfidserial/build/ -lrfidserial
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../rfidserial/build/release/ -lrfidserial
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../rfidserial/build/debug/ -lrfidserial

INCLUDEPATH += $$PWD/../rfidserial
DEPENDPATH += $$PWD/../rfidserial
