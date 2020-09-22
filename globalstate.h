#ifndef GLOBALSTATE_H
#define GLOBALSTATE_H

#include <QObject>

class Algorithm;
class Model;

class ApplicationState : public QObject
{
    Q_OBJECT

public:
    ApplicationState();

    Algorithm* algorithm = nullptr;
    Model* model = nullptr;

public slots:
    void setAlgorithm(Algorithm *palg);
    void setModel(Model *pmodel);
signals:
    void algorithmChanged(Algorithm *palg);
    void modelChanged(Model *pmodel);

};

#endif // GLOBALSTATE_H
