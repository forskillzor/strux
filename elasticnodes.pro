QT += widgets

HEADERS += \
        controllpanel.h \
        drawer.h \
        edge.h \
        graphwidget.h \
        model.h \
        node.h

SOURCES += \
        controllpanel.cpp \
        drawer.cpp \
        edge.cpp \
        graphwidget.cpp \
        main.cpp \
        model.cpp \
        node.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel
