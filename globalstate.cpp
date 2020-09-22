#include "globalstate.h"
#include "algorithm.h"
#include "model.h"

extern ApplicationState appState;

ApplicationState::ApplicationState() : QObject(nullptr)
{
    algorithm  = Algorithm::createAlgorithm(AlgorithmType::BinaryTree);
    model = Model::createModel(ModelType::Tree);
}

void ApplicationState::setAlgorithm(Algorithm *palg)
{
    algorithm = palg;
    emit algorithmChanged(palg);
}

void ApplicationState::setModel(Model *pmodel)
{
    model = pmodel;
    emit modelChanged(pmodel);
}
