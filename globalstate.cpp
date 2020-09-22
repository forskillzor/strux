#include "globalstate.h"

extern GlobalState globalState;

GlobalState::GlobalState()
{
}

void GlobalState::addObserver(Observer *pobsrvr)
{
    observer = pobsrvr;
}
