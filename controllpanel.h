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
    void reset();


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
