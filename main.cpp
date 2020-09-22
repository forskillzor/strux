#include "graphwidget.h"
#include "controllpanel.h"
#include "globalstate.h"

#include <QApplication>
#include <QTime>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>

ApplicationState appState;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *centralWidget = new QWidget;
    ControlPanel *controlPanel= new ControlPanel(&app);

    GraphWidget *graphWidget = new GraphWidget;
    controlPanel->addGraph(graphWidget);

    QMainWindow mainWindow;
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(graphWidget);
    hlayout->addWidget(controlPanel);
    centralWidget->setLayout(hlayout);
    mainWindow.setCentralWidget(centralWidget);

    mainWindow.show();
    return app.exec();
}
