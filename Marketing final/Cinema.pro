
QT       += core gui
QT += widgets multimedia
QT       += core gui sql
QT       +=core gui serialport
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets multimedia
QT += printsupport
QT +=gui
QT += widgets

CONFIG += c++11
TARGET = Cinema.pro

DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    dialog.cpp \
    evenement.cpp \
    login.cpp \
    mailing/emailaddress.cpp \
    mailing/mimeattachment.cpp \
    mailing/mimecontentformatter.cpp \
    mailing/mimefile.cpp \
    mailing/mimehtml.cpp \
    mailing/mimeinlinefile.cpp \
    mailing/mimemessage.cpp \
    mailing/mimemultipart.cpp \
    mailing/mimepart.cpp \
    mailing/mimetext.cpp \
    mailing/quotedprintable.cpp \
    mailing/smtpclient.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    reservation.cpp \
    secdialog.cpp \
    tableprinter.cpp

HEADERS += \
    arduino.h \
    connection.h \
    dialog.h \
    evenement.h \
    login.h \
    mailing/SmtpMime \
    mailing/emailaddress.h \
    mailing/mimeattachment.h \
    mailing/mimecontentformatter.h \
    mailing/mimefile.h \
    mailing/mimehtml.h \
    mailing/mimeinlinefile.h \
    mailing/mimemessage.h \
    mailing/mimemultipart.h \
    mailing/mimepart.h \
    mailing/mimetext.h \
    mailing/quotedprintable.h \
    mailing/smtpclient.h \
    mailing/smtpexports.h \
    mainwindow.h \
    qcustomplot.h \
    reservation.h \
    secdialog.h \
    tableprinter.h

FORMS += \
    dialog.ui \
    login.ui \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    translation.qrc

DISTFILES += \
    ard/ard.ino
