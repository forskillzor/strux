QT += widgets

HEADERS += \
        model/edge.h \
        model/node.h \
        widgets/controllpanel.h \
        widgets/graphwidget.h \
        model/model.h

SOURCES += \
        model/edge.cpp \
        model/node.cpp \
        widgets/controllpanel.cpp \
        widgets/graphwidget.cpp \
        main.cpp \
        model/model.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel \
    elasticnodes_refactoring.qmodel \
    elasticnodes_refactoring.qmodel
