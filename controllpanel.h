#ifndef APPWIDGET_H
#define APPWIDGET_H

#include "algorithm.h"

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

class GraphWidget;

class ControlPanel : public QWidget
{
    Q_OBJECT
    QApplication *application = nullptr;
    GraphWidget *graph = nullptr;

    QButtonGroup *algorithmGroup;

    QRadioButton *binaryTreeRadioButton;
    QRadioButton *quickSortButton;

    QPushButton *applyButton;
    QPushButton *resetButton;

    QPushButton *quitButton;

    void setAlgorithm(int id);
public:
    explicit ControlPanel(QApplication *app);

    void addGraph(GraphWidget* g);
    void printMessage();
};

#endif // APPWIDGET_H
