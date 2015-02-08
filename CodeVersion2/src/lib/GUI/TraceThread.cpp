#include "TraceThread.h"
#include <iostream>

using namespace std;

TraceThread::TraceThread(World * const _worldPtr)
    :   imagePtr(new QImage(_worldPtr->viewPlane->hres, _worldPtr->viewPlane->vres, QImage::Format_ARGB32)),
        worldPtr(_worldPtr)
{
    worldPtr->traceThreadPtr = this;
}

TraceThread::~TraceThread()
{
    if (imagePtr) delete imagePtr;
    cout << "Deleted TraceThread" << endl;
}

void TraceThread::run()
{
    worldPtr->render();
    emit renderUpdate(imagePtr);
    emit renderDone(imagePtr);
}


