QT += widgets

HEADERS += \
        algorithm.h \
        appwidget.h \
        edge.h \
        graphwidget.h \
        model.h \
        modelnode.h \
        viewmodel.h \
        viewnode.h

SOURCES += \
        algorithm.cpp \
        appwidget.cpp \
        edge.cpp \
        graphwidget.cpp \
        main.cpp \
        model.cpp \
        modelnode.cpp \
        viewmodel.cpp \
        viewnode.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel
