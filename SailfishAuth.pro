# The name of your app.
# NOTICE: name defined in TARGET has a corresponding QML filename.
#         If name defined in TARGET is changed, following needs to be
#         done to match new name:
#         - corresponding QML filename must be changed
#         - desktop icon filename must be changed
#         - desktop filename must be changed
#         - icon definition filename in desktop file must be changed
TARGET = SailfishAuth

CONFIG += sailfishapp

SOURCES += src/SailfishAuth.cpp

OTHER_FILES += qml/SailfishAuth.qml \
    qml/cover/CoverPage.qml \
    rpm/SailfishAuth.spec \
    rpm/SailfishAuth.yaml \
    SailfishAuth.desktop \
    qml/pages/MainPage.qml \
    qml/pages/NewAccountDialog.qml
