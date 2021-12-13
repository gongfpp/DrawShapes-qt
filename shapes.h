#ifndef SHAPES_H
#define SHAPES_H

#include <QObject>
#include<QDebug>
class Shapes : public QObject
{
    Q_OBJECT
public:
    explicit Shapes(QObject *parent = nullptr);
    virtual double calcArea()=0;      //计算面积
    virtual double calcPerimeter()=0; //计算周长
    virtual void printInfo()=0;     //显示信息
protected:
    double area;      //面积
    double perimeter; //周长

signals:

public slots:
};

class Rectange:public Shapes
{
private:
    double width,height;   //矩形宽、高
public:
    Rectange();
    Rectange(double,double);
    //计算面积
    double calcArea() ;
    //计算周长
    double calcPerimeter();
    //显示信息
    void printInfo();
};

class Triangle:public Shapes
{
private:
    double a,b,c;         //三角形边长
public:
    Triangle();
    Triangle(double a,double b,double c);
    double calcArea();
    double calcPerimeter();
    void printInfo();
};

#endif // SHAPES_H
