
#include <QApplication>
#include <QTime>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QVector>

#include "graphwidget.h"
#include "controllpanel.h"
#include "model.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // init control
    ControlPanel *controlPanel= new ControlPanel(&app);
    GraphWidget *graphWidget = new GraphWidget;
    controlPanel->setGraph(graphWidget);

    // init window
    QMainWindow mainWindow;
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addWidget(graphWidget);
    hlayout->addWidget(controlPanel);
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(hlayout);
    mainWindow.setCentralWidget(centralWidget);

    mainWindow.show();
    return app.exec();
}
