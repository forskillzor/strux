#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>
#include "model.h"
#include "node.h"

/*******************************
 * Interface Algorithm
 *******************************/

enum class AlgorithmType{ BinaryTree = 1 };

class Algorithm
{
public:
    static Algorithm* createAlgorithm(AlgorithmType type);
    explicit Algorithm();

    virtual void apply() = 0;
    virtual void addItem(Node* node) = 0;
protected:
    Node* item = nullptr;
private:
    Model *model = nullptr;
};

/*******************************
 * Implementations
 *******************************/

class BinaryTreeAlgorytm : public Algorithm
{
public:
    explicit BinaryTreeAlgorytm();

    void apply() override;
    void addItem(Node* node) override;

};

#endif // ALGORITHM_H
