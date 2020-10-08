#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QButtonGroup>
#include <QListWidget>

#include "../model/model.h"

class GraphWidget;

class ControlPanel : public QWidget
{
    Q_OBJECT
public:
    explicit ControlPanel(QApplication *app);
    void setGraph(GraphWidget* g);

private:
    void apply();
    void clear();
    void changeModel(ModelType type);


    QApplication *application = nullptr;
    GraphWidget *graph = nullptr;

    QListWidget* listWidget = nullptr;

    QPushButton *applyButton;
    QPushButton *resetButton;

    QPushButton *quitButton;
};

#endif // APPWIDGET_H
