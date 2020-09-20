#include "algorithm.h"


class BTNode;

/*******************************
 * Interface
 *******************************/

Algorithm::Algorithm(Model *pmodel)
{
    model = pmodel;
}

void Algorithm::apply()
{
//    QVector<int> data = model->getData();
//    for (int item : data) {
//        model->addNode(new BTNode(item));
//    }
}

/*******************************
 * Implementations
 *******************************/

BinaryTreeAlgorytm::BinaryTreeAlgorytm(Model *pmodel) : Algorithm(pmodel)
{
}

void BinaryTreeAlgorytm::apply()
{
}
