#include "treemodelbalanced.h"

TreeModelBalanced::TreeModelBalanced() : Model() { type = ModelType::BalancedTree; }

void TreeModelBalanced::setRoot(ModelItem *item)
{
    root = item;
}

void TreeModelBalanced::addItem(ModelItem *item)
{
    Model::addItem(item);
    if (root)
        root->addItem(item);
    else
        setRoot(item);
}

void TreeModelBalanced::removeItem()
{

}
