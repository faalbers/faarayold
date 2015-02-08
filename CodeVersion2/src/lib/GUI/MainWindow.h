#ifndef __MAINWINDOW__
#define __MAINWINDOW__

#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QtGui/QGraphicsScene>
#include <QtGui/QImage>

#include "Scene/World.h"
#include "GUI/TraceThread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = NULL, Qt::WindowFlags flags = NULL);
    ~MainWindow();
    
    void updateWorld(void);

public slots:
    void renderDone(QImage *imagePtr);
    void renderUpdate(QImage *imagePtr);

protected slots:
    void render();
    //void renderUpdate();

private:
    Ui::MainWindow *ui;
    int             width, height;
    QGraphicsScene  *scene;
    World           *worldPtr;
    TraceThread     *traceThreadPtr;
};


#endif
