#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>

#include "model.h"

class GraphWidget;

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QApplication *app);
    void setGraph(GraphWidget* g);

private:
    void apply();

    QVector<int> data {48, 43, 2, 39, 59, 12, 0, 76, 32, 59, 34, 11, 34, 58,
                      36, 21, 10, 45, 48, 32, 13, 73, 35, 48, 43, 2, 39, 59, 12, 0, 76, 32, 59, 34, 11, 34, 58,
                      36, 21, 10, 45, 48, 32, 13, 73, 35};

    QApplication *application = nullptr;
    Model* model = nullptr;
    GraphWidget *graph = nullptr;

    QButtonGroup *algorithmGroup;

    QRadioButton *binaryTreeRadioButton;
    QRadioButton *quickSortButton;

    QPushButton *applyButton;
    QPushButton *resetButton;

    QPushButton *quitButton;
};

#endif // APPWIDGET_H
