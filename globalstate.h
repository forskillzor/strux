#ifndef GLOBALSTATE_H
#define GLOBALSTATE_H
//#include "algorithm.h"
//#include "model.h"

class Algorithm;
class Model;
class Observer;

class GlobalState
{
public:
    GlobalState();

    Observer *observer = nullptr;
    Algorithm* algorithm = nullptr;
    Model* model = nullptr;

    void addObserver(Observer* pobsrvr);
};

#endif // GLOBALSTATE_H
