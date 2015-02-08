/*
This is where the area is defined where the render result is projected to.
This widget also starts an new build and render of the scene with every
mouse click.
*/

#ifndef __RENDERAREA__
#define __RENDERAREA__

#include <QtGui/QWidget>
#include <QtGui/QPixmap>
#include "Scene/World.h"

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent = 0);
    RenderArea(int width, int height, QWidget* parent = 0);
    ~RenderArea();

    World*      world;
    QPixmap*    pixmap;
    
    QSize sizeHint() const;
    void setSize(QSize size);
    void draw(void) { update(); }
 
protected:
    void paintEvent(QPaintEvent *event);
    //void mousePressEvent(QMouseEvent *event);

private:
    QPixmap*    pixmapOld;
};

#endif
