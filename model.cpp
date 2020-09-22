#include "model.h"

/*******************************
 * Interface Model
 *******************************/

Model::Model()
{
}

Model *Model::createModel(ModelType type)
{
    switch (type) {
        case ModelType::Tree:
            return new TreeModel();
    }
}

void Model::addItem(Node *node)
{
}

QVector<int>& Model::getData()
{
    return data;
}

/*******************************
 * Implementations
 *******************************/

TreeModel::TreeModel() : Model()
{
}

void TreeModel::addItem(Node *node)
{
}
