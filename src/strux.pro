QT += widgets

HEADERS += \
        model/imp/btnodebalanced.h \
        model/imp/treemodelbalanced.h \
        widgets/controllpanel.h \
        widgets/graphwidget.h \
        model/model.h \
        model/edge.h \
        model/node.h \
        model/imp/binarytreenode.h \
        model/imp/treemodel.h

SOURCES += \
        model/imp/btnodebalanced.cpp \
        model/imp/treemodelbalanced.cpp \
        widgets/controllpanel.cpp \
        widgets/graphwidget.cpp \
        model/model.cpp \
        model/edge.cpp \
        model/node.cpp \
        model/imp/binarytreenode.cpp \
        model/imp/treemodel.cpp \
        main.cpp

# install
target.path = /home/student/qtprojects/installs/
INSTALLS += target
