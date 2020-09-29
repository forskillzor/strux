#include "model.h"
#include <QDebug>

/*
 * Factory
 */

Model::Model(GraphWidget* pwidget)
    :graph(pwidget)
{
    inputData = generateData();
}

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

ModelItem *Model::createItem(int value)
{
    switch (type) {
    case ModelType::Empty:
        break;
    case ModelType::Tree:
        return new BinaryTreeNode(value, graph);
    }
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
        root = static_cast<BinaryTreeNode*>(item);
    }
}

void TreeModel::removeItem() { }

ModelItem *TreeModel::getRoot() { return root; }

ModelType TreeModel::getType() { return type; }

/*
 * Implementations BinaryTreeNode
 */

//WARNING must be removed or implement
void BinaryTreeNode::connect(BinaryTreeNode *parent, BinaryTreeNode *child)
{
    parent->setParent(child);
}

BinaryTreeNode::BinaryTreeNode(int val, GraphWidget* pwidget)
    : ViewNode(val, pwidget), ModelItem()
{
    value = val;
//    QPropertyAnimation animation(this, "position");
//    animation.setDuration(1000);
//    animation.setStartValue(QPointF());
//    animation.setStartValue(QPointF());
//    animation.start();
}

BinaryTreeNode::~BinaryTreeNode()
{
    delete this;
}

void BinaryTreeNode::setParent(ModelItem *pparent)
{
    static int shift = 200;
    BinaryTreeNode* node = static_cast<BinaryTreeNode*>(pparent);
//    ViewNode* vself = static_cast<ViewNode*>(this);
    BinaryTreeNode* vself = this;
//    ViewNode* vparent = dynamic_cast<ViewNode*>(pparent);
    BinaryTreeNode* vparent = static_cast<BinaryTreeNode*>(pparent);
    addToGraph(new ViewEdge(vself, vparent));
    if (node->level == 1) {
        vparent->setY(-200);
    }

    if (value < pparent->getValue()) {
        vself->setX(vparent->x() - (shift / (level - 1)));
    }
    if (value >= pparent->getValue()) {
        vself->setX(vparent->x() + (shift / (level - 1)));
    }
    vself->setY(vparent->y()+ vself->getHeight());

    parent = node;
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
