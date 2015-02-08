#include "GUI/MainWindow.h"
#include "GUI/ui_MainWindow.h"
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGraphicsScene>
#include <QtGui/QImage>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    :   QMainWindow(parent, flags),
        ui(new Ui::MainWindow),
        width(500),
        height(500),
        scene(new QGraphicsScene),
        worldPtr(new World),
        traceThreadPtr(NULL)
{
    ui->setupUi(this);
    setWindowTitle(tr("FAARay"));

    //scene->setSceneRect(0, 0, width, height);
    ui->renderView->setScene(scene);
    
    connect(ui->render, SIGNAL(clicked()), this, SLOT(render()));
    
    /*
    renderArea = new RenderArea(ui->width->value(), ui->height->value());
    ui->renderLayout->addWidget(renderArea);
    
    connect(ui->render, SIGNAL(clicked()), this, SLOT(render()));
    connect(ui->renderUpdate, SIGNAL(clicked()), this, SLOT(renderUpdate()));
    */
}

MainWindow::~MainWindow()
{
    if (scene)      delete scene;
    if (worldPtr)   delete worldPtr;
}

void MainWindow::updateWorld()
{
    QSize imageSize =  ui->renderView->size();

    //worldPtr->viewPlane->hres = imageSize.width();
    //worldPtr->viewPlane->vres = imageSize.height();
    worldPtr->viewPlane->hres = ui->width->value();
    worldPtr->viewPlane->vres = ui->height->value();
    
    switch (ui->cpus->currentIndex()) {
        case 0:
            worldPtr->setRayCastTracer();
            worldPtr->multiCPUs = false;
            break;
        case 1:
            worldPtr->multiCPUs = true;
            break;
        default:
            worldPtr->multiCPUs = false;
            break;
    }

    worldPtr->setPinholeCamera(
        Point3D(
            ui->cameraX->value(),
            ui->cameraY->value(),
            ui->cameraZ->value()),
        Point3D(
            ui->lookAtX->value(),
            ui->lookAtY->value(),
            ui->lookAtZ->value()),
        ui->vpDistance->value(),
        ui->zoom->value());

    worldPtr->viewPlane->setNumSamples(ui->samples->value());

    switch (ui->tracer->currentIndex()) {
        case 0:
            worldPtr->setRayCastTracer();
            break;
        case 1:
            worldPtr->setAreaLightingTracer();
            break;
        default:
            worldPtr->setRayCastTracer();
            break;
    }

    switch (ui->ambient->currentIndex()) {
        case 0:
            worldPtr->setAmbientLight(ui->ambientRadiance->value());
            break;
        case 1:
            worldPtr->setAmbientOccluderLight(ui->ambientRadiance->value());
            break;
        default:
            worldPtr->setAmbientLight(ui->ambientRadiance->value());
            break;
    }
}

void MainWindow::render()
{
    ui->render->setDisabled(true);
    
    //QSize imageSize =  ui->renderView->size();
    //ui->renderView->scene()->setSceneRect(0,0,imageSize.width(), imageSize.height());
    
    updateWorld();
    
    scene->clear();
    scene->setSceneRect(0, 0, worldPtr->viewPlane->hres, worldPtr->viewPlane->vres);
    
    traceThreadPtr = new TraceThread(worldPtr);
    connect(traceThreadPtr, SIGNAL(renderDone(QImage*)),this, SLOT(renderDone(QImage*)));
    connect(traceThreadPtr, SIGNAL(renderUpdate(QImage*)),this, SLOT(renderUpdate(QImage*)));
    traceThreadPtr->start();

}

void MainWindow::renderDone(QImage *imagePtr)
{
    if (traceThreadPtr) {
        traceThreadPtr->wait();
        delete traceThreadPtr;
        traceThreadPtr = NULL;
    }
    ui->render->setDisabled(false);
}

void MainWindow::renderUpdate(QImage *imagePtr)
{
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(*imagePtr));
}

/*
void MainWindow::renderUpdate()
{
    renderArea->update();
}
*/

