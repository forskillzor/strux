QT += widgets

HEADERS += \
        widgets/controllpanel.h \
        widgets/graphwidget.h \
        model/model.h \
        model/edge.h \
        model/node.h \
        model/imp/binarytreenode.h \
        model/imp/treemodel.h

SOURCES += \
        widgets/controllpanel.cpp \
        widgets/graphwidget.cpp \
        model/model.cpp \
        model/edge.cpp \
        model/node.cpp \
        model/imp/binarytreenode.cpp \
        model/imp/treemodel.cpp \
        main.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel \
    elasticnodes_refactoring.qmodel \
    elasticnodes_refactoring.qmodel
