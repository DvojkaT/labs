#define _USE_MATH_DEFINES
#include "Figure.h"
#include <cmath>
#include "Error.h"
//Circle

double Circle::findArea()
{
	return M_PI * r * r;
}

double Circle::findPerimeter()
{
	return 2 * M_PI * r;
}

int Circle::getR()
{
	return r;
}

void Circle::setR(int r)
{
    this->r = r;
}

Circle::Circle(int r)
{
	if (r > 0) this->r = r;
    else throw Error("Error creating circle");
}

Circle::~Circle()
{

}

//Triangle

double Triangle::findArea()
{
    double p = findPerimeter() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::findPerimeter()
{
	return a + b + c;
}

double Triangle::getSide(int number)
{
	switch (number)
	{
	case 1:
	{
		return a;
	}
	case 2:
	{
		return b;
	}
	case 3:
	{
		return c;
	}
	default:
		break;
	}
    throw Error("Error select side");
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a)
	{
        this->a = a;
        this->b = b;
        this->c = c;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
	}
    else throw Error("Error creating triangle");
}

void Triangle::getCoords(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3)
{
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x3;
    y3 = this->y3;
}

Triangle::~Triangle()
{

}
//Triangle in circle(my figure)
/*double TriangleInCircle::findArea()
{
    double p = findPerimeter()/2;
    return M_PI * r* r - sqrt(p * (p - a) * (p - b) * (p - c));

}

double TriangleInCircle::findPerimeter()
{
    return a+b+c;
}


TriangleInCircle::~TriangleInCircle()
{

}

TriangleInCircle::TriangleInCircle(int x1, int y1,int x2, int y2, int x3,int y3,int r)
{
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a && a<=2*r && b<= 2*r && c<=2*r)
    {

    }
    else throw Error("Error creating triangle in circle");
}
void TriangleInCircle::getCoords(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &r)
{
    x1 = this->x1;
    y1 = this->y1;
    x2 = this->x2;
    y2 = this->y2;
    x3 = this->x3;
    y3 = this->y3;
    r = this->r;

}
*/
