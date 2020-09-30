QT += widgets

HEADERS += \
        controllpanel.h \
        graphwidget.h \
        model.h \
        view.h \
        viewnode.h

SOURCES += \
        controllpanel.cpp \
        graphwidget.cpp \
        main.cpp \
        model.cpp \
        view.cpp \
        viewnode.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/graphicsview/elasticnodes
INSTALLS += target

DISTFILES += \
    elasticnodes.qmodel \
    elasticnodes_refactoring.qmodel \
    elasticnodes_refactoring.qmodel
