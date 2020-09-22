#include "graphwidget.h"
#include "controllpanel.h"
#include "globalstate.h"

#include <QApplication>
#include <QTime>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>

GlobalState globalState;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *centralWidget = new QWidget;
    ControlPanel *appwidget = new ControlPanel(&app);

    GraphWidget *graphWidget = new GraphWidget;
    globalState.addObserver(graphWidget);
    appwidget->addGraph(graphWidget);

    QMainWindow mainWindow;
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(graphWidget);
    hlayout->addWidget(appwidget);
    centralWidget->setLayout(hlayout);
    mainWindow.setCentralWidget(centralWidget);

    mainWindow.show();
    return app.exec();
}
