QT += widgets

HEADERS += \
        view/viewitem.h \
        widgets/controllpanel.h \
        widgets/graphwidget.h \
        model/model.h \
        view/viewedge.h \
        view/viewnode.h

SOURCES += \
        view/viewitem.cpp \
        widgets/controllpanel.cpp \
        widgets/graphwidget.cpp \
        main.cpp \
        model/model.cpp \
        view/viewedge.cpp \
        view/viewnode.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel \
    elasticnodes_refactoring.qmodel \
    elasticnodes_refactoring.qmodel
