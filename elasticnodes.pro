QT += widgets

HEADERS += \
        widgets/controllpanel.h \
        widgets/graphwidget.h \
        model/model.h \
        view/view.h \
        view/viewnode.h

SOURCES += \
        widgets/controllpanel.cpp \
        widgets/graphwidget.cpp \
        main.cpp \
        model/model.cpp \
        view/view.cpp \
        view/viewnode.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel \
    elasticnodes_refactoring.qmodel \
    elasticnodes_refactoring.qmodel
