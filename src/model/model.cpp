#include <QDebug>

#include "model.h"
#include "../widgets/graphwidget.h"
#include "../model/node.h"
#include "../model/edge.h"

Model::Model(GraphWidget* pwidget)
    :graph(pwidget)
{
    inputData = generateData();
    ModelItem::model = this;
}

/*
 * Factory
 */

Model* Model::createModel(ModelType type, GraphWidget* pwidget)
{
    switch (type) {
        case ModelType::Empty:
            return nullptr;
        case ModelType::Tree:
            return new TreeModel(pwidget);
    }
}

QVector<int>* Model::generateData()
{
    QVector<int>* result = new QVector<int>;
    QRandomGenerator* generator = new QRandomGenerator;
    QTime timer(QTime::currentTime());
    generator->seed(timer.msecsSinceStartOfDay());
    for (int i = 0; i < 20; ++i) {
        result->push_back(generator->bounded(0,100));
    }
    return result;
}

Model* ModelItem::model = nullptr;

ModelItem *Model::createItem(int value)
{
    switch (type) {
    case ModelType::Empty:
        break;
    case ModelType::Tree:
        return new BinaryTreeNode(value);
    }
    return nullptr;
}

void Model::readData(QVector<int>* pdata )
{
    addItem(createItem(pdata->at(0)));
}

void Model::clear()
{
    root = nullptr;
}

ModelItem::~ModelItem()
{
    delete this;
}

/*
 *  Implementations TreeModel
 */

TreeModel::TreeModel(GraphWidget* pwidget) : Model(pwidget) { type = ModelType::Tree; }

void TreeModel::addItem(ModelItem *item)
{
        if (root)
        root->addItem(item);
    else {
        root = item;
    }
}

void TreeModel::removeItem() { }


/*
 * Implementations BinaryTreeNode
 */

BinaryTreeNode::BinaryTreeNode(int val)
    : ModelItem()
{
    value = val;
}

BinaryTreeNode::~BinaryTreeNode()
{
    delete this;
}
//WARNING draw logic move from here
void BinaryTreeNode::setParent(ModelItem *pparent)
{
}

void BinaryTreeNode::addItem(ModelItem *item)
{
    BinaryTreeNode* node = static_cast<BinaryTreeNode*>(item);
    node->level++;

    if (node->getValue() < value) {
        if (left) {
            left->addItem(item);
        }
        else {
            left = node;
            left->setParent(this);
            return;
        }
    }
    else if (node->getValue() >= value) {
        if (right){
            right->addItem(item);
        }
        else {
            right = node;
            right->setParent(this);
            return;
        }
    }
    else
        ++count;
}

void BinaryTreeNode::removeItem()
{
}
