#include "shapes.h"
#include "math.h"

Shapes::Shapes(QObject *parent) : QObject(parent)
{

}

Rectange::Rectange()
{

}

Rectange::Rectange(double wid, double hei)
{
    width = wid;
    height = hei;
    calcArea();
    calcPerimeter();
}

double Rectange::calcArea()
{
    area=width*height;
    return area;
}

double Rectange::calcPerimeter()
{
    perimeter=(width+height)*2;
    return perimeter;
}

void Rectange::printInfo()
{
    qDebug() << "矩形的面积为:"<<area<<",周长为:"<<perimeter;
}

Triangle::Triangle()
{

}

Triangle::Triangle(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    calcArea();
    calcPerimeter();
}

double Triangle::calcArea()
{
    double p=(a+b+c)/2;
    area=sqrt(p*(p-a)*(p-b)*(p-c));
    return area;
}

double Triangle::calcPerimeter()
{
    perimeter=a+b+c;
    return  perimeter;
}

void Triangle::printInfo()
{
    qDebug()<<"三角形的面积为:"<<area<<",周长为:"<<perimeter;

}
