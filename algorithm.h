#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>
#include "model.h"

/*******************************
 * Interface Algorithm
 *******************************/

class Algorithm
{
public:
    Algorithm(Model *pmodel);
    virtual void apply();
private:
    Model *model = nullptr;
};

/*******************************
 * Implementations
 *******************************/

class BinaryTreeAlgorytm : public Algorithm
{
public:
    BinaryTreeAlgorytm(Model *pmodel);

    void apply() override;

};

#endif // ALGORITHM_H
