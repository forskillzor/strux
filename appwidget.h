#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
#include <QPushButton>

class AppWidget : public QWidget
{
    Q_OBJECT
    QApplication *application = nullptr;

    QPushButton *applyButton;
    QPushButton *resetButton;
    QPushButton *addNodeButton;
    QPushButton *removeNodeButton;
    QPushButton *nextStepButton;
    QPushButton *quitButton;
public:
    explicit AppWidget(QApplication *app);
};

#endif // APPWIDGET_H
