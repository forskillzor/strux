#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QVector>

enum class ModelType { Tree = 1 };

class Node;
/*******************************
 * Interface Model
 *******************************/

class Model
{
    Node *root = nullptr;

    QVector<int> data {3, 5, 1, 9, 7, 6, 4, 8, 2, 0};
    QVector<Node*> nodes;
public:
    Model();

    static Model* createModel(ModelType type);
    virtual void addItem(Node *node) = 0;
    QVector<int>& getData();

};

/*******************************
 * Implementations
 *******************************/

class TreeModel : public Model
{
public:
    explicit TreeModel();
    void addItem(Node *node) override;
};

#endif // TREEMODEL_H
