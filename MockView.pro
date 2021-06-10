QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Controller/gamecontroller.cpp \
        Controller/logincontroller.cpp \
        Controller/menucontroller.cpp \
        Controller/registercontroller.cpp \
        Model/gamemodel.cpp \
        Model/move.cpp \
        Model/personmodel.cpp \
        View/gameview.cpp \
        View/loginview.cpp \
        main.cpp

RESOURCES += qml.qrc
            filename.txt

TRANSLATIONS += \
    MockView_vi_VN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Controller/gamecontroller.h \
    Controller/logincontroller.h \
    Controller/menucontroller.h \
    Controller/registercontroller.h \
    Model/gamemodel.h \
    Model/move.h \
    Model/personmodel.h \
    View/gameview.h \
    View/loginview.h

DISTFILES +=
