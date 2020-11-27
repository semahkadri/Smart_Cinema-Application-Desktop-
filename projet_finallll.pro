QT       += core gui sql gui multimedia multimediawidgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia core printsupport

CONFIG += c++11 console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connexion.cpp \
    cruds_films.cpp \
    cruds_salles.cpp \
    gestion_film.cpp \
    gestion_salles.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    connexion.h \
    cruds_films.h \
    cruds_salles.h \
    gestion_film.h \
    gestion_salles.h \
    login.h \
    mainwindow.h

FORMS += \
    gestion_film.ui \
    gestion_salles.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mouna.qrc
