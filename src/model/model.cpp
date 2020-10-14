#include <QDebug>

#include "model.h"
#include "model/imp/binarytreenode.h"
#include "model/imp/treemodel.h"
#include "model/imp/treemodelbalanced.h"
#include "model/imp/btnodebalanced.h"

Model::Model()
{
    inputData = generateData();
    ModelItem::model = this;
}

/*
 * Factory
 */

Model* Model::createModel(ModelType type)
{
    switch (type) {
        case ModelType::Empty:
            return nullptr;
        case ModelType::Tree:
            return new TreeModel;
        case ModelType::BalancedTree:
            return new TreeModelBalanced;
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
        return new BTNode(value);
    case ModelType::BalancedTree:
        return new BTNodeBalanced(value);
    }
    return nullptr;
}

void Model::addItem(ModelItem *item)
{
    item->startAnimation();
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
