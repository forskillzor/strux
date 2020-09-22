QT += widgets

HEADERS += \
        algorithm.h \
        controllpanel.h \
        edge.h \
        globalstate.h \
        graphwidget.h \
        model.h \
        node.h

SOURCES += \
        algorithm.cpp \
        controllpanel.cpp \
        edge.cpp \
        globalstate.cpp \
        graphwidget.cpp \
        main.cpp \
        model.cpp \
        node.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel
