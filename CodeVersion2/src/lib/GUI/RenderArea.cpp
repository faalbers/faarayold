#include "GUI/RenderArea.h"
#include <QtGui/QPainter>

RenderArea::RenderArea(QWidget* parent)
    :   QWidget(parent),
        pixmap(NULL),
        pixmapOld(NULL),
        world(NULL)
{
    pixmap = new QPixmap(10, 10);
    world = new World(this);
    pixmap->fill(Qt::black);
}

RenderArea::RenderArea(int width, int height, QWidget* parent)
    :   QWidget(parent),
        pixmap(NULL),
        pixmapOld(NULL),
        world(NULL)
{
    pixmap = new QPixmap(width, height);
    world = new World(this);
    pixmap->fill(Qt::black);
}

RenderArea::~RenderArea()
{
    if (world) delete(world);
    if (pixmap) delete(pixmap);
}

QSize RenderArea::sizeHint() const
{
    return pixmap->size();
}

void RenderArea::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);
    if (pixmap)
        painter.drawPixmap(0, 0, *pixmap);
    if (pixmapOld) {
        delete pixmapOld;
        pixmapOld = NULL;
    }
}

void RenderArea::setSize(QSize size)
{
    QPixmap*    pixmapOld;
    if ( pixmap ) {
        if ( size == pixmap->size() ) return;
        pixmapOld = pixmap;
        pixmap = new QPixmap(size);
        world->updateViewPlane();
    }
    pixmap->fill(Qt::black);
}


