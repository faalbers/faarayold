#ifndef __TRACETHREAD__
#define __TRACETHREAD__

#include <QtCore/QThread>
#include <QtGui/QImage>
#include <QtGui/QPushButton>
#include "Scene/World.h"

class World;

class TraceThread : public QThread
{
    Q_OBJECT

public:
    TraceThread(World * const _worldPtr);
    ~TraceThread();

    void updateImage() { emit renderUpdate(imagePtr); }
    
    QImage   *imagePtr;

protected:
    void run();

signals:
    void renderDone(QImage *_imagePtr);
    void renderUpdate(QImage *_imagePtr);

private:
    World * const   worldPtr;
    QPushButton     *renderButtonPtr;
};

#endif
