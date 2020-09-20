#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>

enum class ModelType { Tree = 1 };

class ModelNode;

/*******************************
 * Interface Model
 *******************************/

class Model
{
    ModelNode *root;

    QVector<int> data {3, 5, 1, 9, 7, 6, 4, 8, 2, 0};
    QVector<ModelNode*> nodes;
public:
    Model();

    Model* createModel(ModelType type);
    virtual void addItem(ModelNode *node);
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
