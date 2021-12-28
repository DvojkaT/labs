#pragma once
class Figure
{
public:
    virtual double findArea() = 0;
    virtual double findPerimeter() = 0;
};

class Circle : public Figure
{
private:
    int r;
public:
    double findArea();
    double findPerimeter();
    int getR();
    void setR(int r);

    Circle(int r);
    virtual ~Circle();
};

class Triangle : public Figure
{
private:
	double a;
	double b;
	double c;
    int x1, y1,
    x2, y2,
    x3, y3;
public:
	enum side{
		A = 1,
		B = 2,
		C = 3,
	};
    double findArea();
    double findPerimeter();
    double getSide(int number);
    void getCoords(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3);

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    virtual ~Triangle();
};

/*class TriangleInCircle : public Figure
{
private:
    double a,b,c;
    int x1,x2,x3,y1,y2,y3,r;
public:
    double findArea();
    double findPerimeter();

    TriangleInCircle(int x1,int y1, int x2, int y2, int x3,int y3,int r);
    void getCoords(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3,int& r);
    virtual ~TriangleInCircle();
};
*/
