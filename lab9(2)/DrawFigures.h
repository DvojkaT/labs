#ifndef DRAWFIGURES_H
#define DRAWFIGURES_H

#include <QGraphicsItem>
#include "Figure.h"
#include <QPainter>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QStyleOptionGraphicsItem>
class FigureDraw : public QGraphicsItem
{
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QPointF point;
    QPointF position;
    QColor color = QRgb(688590);

protected:
    QPainterPath path;
    QRectF bounding;
    Figure* figure;
    FigureDraw(QPoint position);
    void updateInfo();
public:
    virtual ~FigureDraw();
};

class CircleDraw : public FigureDraw
{
private:
    void Draw();
public:
    CircleDraw(Circle circle, QPoint position);
    ~CircleDraw();
};

class TriangleDraw : public FigureDraw
{
private:
    void Draw();
public:
    TriangleDraw(Triangle triangle, QPoint position);
    ~TriangleDraw();
};

/*class TriangleInCircleDraw : public FigureDraw
{
private:
    void Draw();
public:
    TriangleInCircleDraw(TriangleInCircle ttriangleincircle, QPoint position);
    ~TriangleInCircleDraw();
};*/

#endif // DRAWFIGURES_H
