#include "controllpanel.h"
#include "globalstate.h"
#include "algorithm.h"
#include "graphwidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QCoreApplication>

extern GlobalState globalState;


ControlPanel::ControlPanel(QApplication *app) : QWidget(nullptr), application(app)
{
    // Control Panel Widget
    QWidget *topControlls = new QWidget;
    topControlls->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    QVBoxLayout *topPanelLayout = new QVBoxLayout;
    topControlls->setLayout(topPanelLayout);

    // RadioButton Group
    binaryTreeRadioButton = new QRadioButton("Binary Tree", this);
    quickSortButton = new QRadioButton("Quick Sort", this);
    algorithmGroup = new QButtonGroup(this);
    algorithmGroup->addButton(binaryTreeRadioButton);
    algorithmGroup->addButton(quickSortButton);

    applyButton = new QPushButton("Apply", this);
    resetButton = new QPushButton("Reset View", this);
    quitButton = new QPushButton("Quit", this);
    // Main AppWidget Layout
    QVBoxLayout *vlayout = new QVBoxLayout;
    topPanelLayout->addWidget(binaryTreeRadioButton);
    topPanelLayout->addWidget(quickSortButton);
    topPanelLayout->addWidget(applyButton);
    topPanelLayout->addWidget(resetButton);
    vlayout->addWidget(topControlls);
    // Vertical Spacer
    QSpacerItem *controlPanelVSpacer =  new QSpacerItem(10, 400, QSizePolicy::Fixed, QSizePolicy::Expanding);
    vlayout->addSpacerItem(controlPanelVSpacer);
    vlayout->addWidget(quitButton);
    setLayout(vlayout);

    connect(quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit);
    connect(applyButton, &QPushButton::clicked, this, &ControlPanel::setAlgorithm);
    connect(algorithmGroup, QOverload<int>::of(&QButtonGroup::buttonPressed),
            this, &ControlPanel::setAlgorithm);
    connect(resetButton, &QPushButton::clicked, [=](){graph->resetView();} );
}

void ControlPanel::addGraph(GraphWidget *g)
{
    graph = g;
}

void ControlPanel::setAlgorithm(int id)
{
//    globalState.algorithm = Algorithm::createAlgorithm(AlgorithmType::BinaryTree);
}
