#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>

class BTNode;

/*******************************
 * Interface Model
 *******************************/

class Model
{
    BTNode *root;

    QVector<int> data {3, 5, 1, 9, 7, 6, 4, 8, 2, 0};
    QVector<BTNode*> nodes;
public:
    Model();

    virtual void addItem(BTNode *node);
    QVector<int>& getData();

};

/*******************************
 * Implementations
 *******************************/

class TreeModel : public Model
{
public:
    explicit TreeModel();
};

#endif // TREEMODEL_H
