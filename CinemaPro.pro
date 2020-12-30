QT       += network sql printsupport serialport widgets multimedia core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=  c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    database.cpp \
    dialog.cpp \
    gabonnements.cpp \
    gesemployee.cpp \
    gesevenement.cpp \
    gesfilm.cpp \
    gesparking.cpp \
    gesproduit.cpp \
    gesprofil.cpp \
    gessalle.cpp \
    greservation.cpp \
    gsubscribers.cpp \
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
    secdialog.cpp \
    statistics.cpp \
    welcomewidget.cpp

HEADERS += \
    arduino.h \
    database.h \
    dialog.h \
    gabonnements.h \
    gesemployee.h \
    gesevenement.h \
    gesfilm.h \
    gesparking.h \
    gesproduit.h \
    gesprofil.h \
    gessalle.h \
    greservation.h \
    gsubscribers.h \
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
    secdialog.h \
    statistics.h \
    welcomewidget.h

FORMS += \
    dialog.ui \
    secdialog.ui \
    statistics.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/release/ -lcomponents
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/debug/ -lcomponents
else:unix: LIBS += -L$$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/ -lcomponents

INCLUDEPATH += $$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/debug
DEPENDPATH += $$PWD/../../Desktop/Codes/build-qt-material-widgets-Desktop_Qt_5_9_9_MinGW_32bit-Debug/components/debug

RESOURCES += \
    images/resources.qrc
