#include "appwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QCoreApplication>

AppWidget::AppWidget(QApplication *app) : QWidget(nullptr), application(app)
{
    applyButton = new QPushButton("Apply algorithm", this);
    resetButton = new QPushButton("Reset View", this);
    addNodeButton = new QPushButton("Add Node", this);
    removeNodeButton = new QPushButton("Remove Node", this);
    nextStepButton = new QPushButton("Next Step", this);
    quitButton = new QPushButton("Quit", this);
    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(applyButton);
    vlayout->addWidget(resetButton);
    vlayout->addWidget(addNodeButton);
    vlayout->addWidget(removeNodeButton);
    vlayout->addWidget(nextStepButton);
    vlayout->addWidget(nextStepButton);
    vlayout->addSpacing(400);
    vlayout->addWidget(quitButton);
    setLayout(vlayout);

    QObject::connect(quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit);
}

void AppWidget::quitApp()
{
}

