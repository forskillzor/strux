#include "controllpanel.h"
#include "graphwidget.h"
#include "drawer.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QCoreApplication>

// for debuging
#include <QDebug>

ControlPanel::ControlPanel(QApplication *app) : QWidget(nullptr), application(app)
{
    setMaximumWidth(250);
    // Control Panel Widget

    QWidget *topControlls = new QWidget;
    topControlls->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QVBoxLayout *topPanelLayout = new QVBoxLayout;
    topControlls->setLayout(topPanelLayout);

    // List Widget

    listWidget = new QListWidget(this);
    listWidget->setMinimumHeight(400);
    listWidget->addItem("Binary Tree");
    listWidget->addItem("Binary Tree Weighted");
    listWidget->addItem("Binary Tree Balansed");

    // Buttons

    applyButton = new QPushButton("Apply", this);
    resetButton = new QPushButton("Reset View", this);
    quitButton = new QPushButton("Quit", this);

    // Main AppWidget Layout

    QVBoxLayout *vlayout = new QVBoxLayout;
    topPanelLayout->addWidget(applyButton);
    topPanelLayout->addWidget(resetButton);
    vlayout->addWidget(listWidget);
    vlayout->addWidget(topControlls);

    // Vertical Spacer

    QSpacerItem *controlPanelVSpacer =  new QSpacerItem(10, 400, QSizePolicy::Fixed, QSizePolicy::Expanding);
    vlayout->addSpacerItem(controlPanelVSpacer);
    vlayout->addWidget(quitButton);
    setLayout(vlayout);

    // CONNECTIONS

    connect(applyButton, &QPushButton::clicked, this, &ControlPanel::apply);
    connect(quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit);
    connect(resetButton, &QPushButton::clicked, this, &ControlPanel::clear);
//    connect(listWidget, &QListWidget::itemClicked, this, &ControlPanel::changeModel);
}

void ControlPanel::setGraph(GraphWidget *pgraph)
{
    graph = pgraph;
}

void ControlPanel::apply()
{
    graph->readData();
    //WARNING graph->drawModel();
//    graph->drawModel();
}

void ControlPanel::clear()
{
    graph->clear();
}

void ControlPanel::changeModel(ModelType type)
{
    graph->changeModel(type);
}
