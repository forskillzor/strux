QT += widgets

HEADERS += \
        controllpanel.h \
        drawer.h \
        graphwidget.h \
        model.h \
        view.h

SOURCES += \
        controllpanel.cpp \
        drawer.cpp \
        graphwidget.cpp \
        main.cpp \
        model.cpp \
        view.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel
