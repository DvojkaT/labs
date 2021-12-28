#include "DrawFigures.h"

FigureDraw::FigureDraw(QPoint position)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    this->position = position;
    setPos(position);
}

void FigureDraw::updateInfo()
{
   QString InfoCoor = QString("\nКоординаты: %1, %2").arg(position.x()).arg((position.y()));
   QString InfoFigure = QString("Площадь: %1\nПериметр: %2").arg(figure->findArea()).arg(figure->findPerimeter());
   setToolTip(InfoFigure);
}

void FigureDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(color);
    painter->drawPath(path);
    if(isSelected() == true)
    {
        painter->restore();
        painter->setPen(QPen(Qt::DashLine));
        painter->drawRect(bounding);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF FigureDraw::boundingRect() const
{
    return QRectF(bounding);
}

FigureDraw::~FigureDraw(){}

void FigureDraw::mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
    point = mouseEvent->pos();
    if (mouseEvent->button() == Qt::RightButton)
    {
        setSelected(!isSelected());
    }
    else
    {
        this->setCursor(QCursor(Qt::ClosedHandCursor));
    }
}

void FigureDraw::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    setPos(QPoint(mouseEvent->scenePos().x()- point.x(),mouseEvent->scenePos().y()-point.y()));
    position = mouseEvent->scenePos();
}

void FigureDraw::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    updateInfo();
    Q_UNUSED(mouseEvent);
}
//Circle
CircleDraw::CircleDraw(Circle circle, QPoint position) : FigureDraw(position)
{
    figure = new Circle(circle);
    Draw();
    updateInfo();
}

void CircleDraw::Draw()
{
    path = QPainterPath();
    int r = ((Circle*)figure)->getR();
    path.addEllipse(0, 0, r, r);
    bounding = QRectF(QGraphicsEllipseItem(0, 0, r, r).boundingRect());
}

CircleDraw::~CircleDraw()
{
    delete (Circle*)figure;
}
//Triangle
TriangleDraw::TriangleDraw(Triangle triangle, QPoint position) : FigureDraw(position)
{
    figure = new Triangle(triangle);
    Draw();
    updateInfo();
}

void TriangleDraw::Draw()
{
    path = QPainterPath();
    int x1, y1, x2, y2, x3, y3;
    ((Triangle*)figure)->getCoords(x1, y1, x2, y2, x3, y3);
    path.addPolygon(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3)}));
    bounding = QRectF(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3)}).boundingRect());
}

TriangleDraw::~TriangleDraw()
{
    delete (Triangle*)figure;
}
//TriangleInCircle
/*TriangleInCircleDraw::TriangleInCircleDraw(TriangleInCircle triangleincircle, QPoint position) : FigureDraw(position)
{
    figure = new TriangleInCircle(triangleincircle);
    Draw();
    updateInfo();
}

void TriangleInCircleDraw::Draw()
{
    path = QPainterPath();
    int x1,y1,x2,y2,x3,y3,r;
    ((TriangleInCircle*)figure)->getCoords(x1,y1,x2,y2,x3,y3,r);
    path.addEllipse(0, 0, r, r);
    //path.addPolygon(QPolygon(QList<QPoint>{QPoint(x1, y1), QPoint(x2, y2), QPoint(x3, y3)}));
    bounding = QRectF(QGraphicsEllipseItem(0, 0, r, r).boundingRect());
}

TriangleInCircleDraw::~TriangleInCircleDraw()
{
    delete (TriangleInCircle*)figure;
}
*/
