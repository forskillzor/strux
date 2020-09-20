#include "algorithm.h"


class BTNode;

/*******************************
 * Interface
 *******************************/

Algorithm::Algorithm(Model *pmodel)
{
    model = pmodel;
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
