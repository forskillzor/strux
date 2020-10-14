#include "treemodel.h"

/*
 *  Implementations TreeModel
 */

TreeModel::TreeModel() : Model() { type = ModelType::Tree; }

void TreeModel::setRoot(ModelItem *item)
{
    root = item;
}

void TreeModel::addItem(ModelItem *item)
{
    Model::addItem(item);
    if (root)
        root->addItem(item);
    else {
        setRoot(item);
    }
}

void TreeModel::removeItem() { }

