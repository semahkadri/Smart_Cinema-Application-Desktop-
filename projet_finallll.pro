QT       += core gui sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia core

CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    cruds_employer.cpp \
    cruds_profil.cpp \
    gestion_employer.cpp \
    gestion_profil.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connexion.h \
    cruds_employer.h \
    cruds_profil.h \
    gestion_employer.h \
    gestion_profil.h \
    login.h \
    mainwindow.h

FORMS += \
    gestion_employer.ui \
    gestion_profil.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
