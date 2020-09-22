#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>

/*******************************
 * Interface Algorithm
 *******************************/

class ModelItem;
class Model;

enum class AlgorithmType{ BinaryTree = 1 };

class Algorithm
{
public:
    // Factory Method
    static Algorithm* createAlgorithm(AlgorithmType type);

    virtual void apply() = 0;
    virtual void addItem(ModelItem *self, ModelItem* node) = 0;

protected:
    Model* model;
};

/*******************************
 * Imp BinaryTreeAlgorithm
 *******************************/

class BinaryTreeAlgorytm : public Algorithm
{
public:
    explicit BinaryTreeAlgorytm();

    void apply() override;
    void addItem(ModelItem *self, ModelItem* node) override;
};

#endif // ALGORITHM_H
