QT += widgets

HEADERS += \
        algorithm.h \
        appwidget.h \
        btnode.h \
        edge.h \
        graphwidget.h \
        model.h \
        viewmodel.h \
        viewnode.h

SOURCES += \
        algorithm.cpp \
        appwidget.cpp \
        btnode.cpp \
        edge.cpp \
        graphwidget.cpp \
        main.cpp \
        model.cpp \
        viewmodel.cpp \
        viewnode.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target
