#include <iostream>


using namespace std;

class Figure
{
protected:
    string name;

public:
    virtual void print() = 0;

    string get_name()
    {
        return name;
    }

    void set_name(string name)
    {
        this->name = name;
    }

};

class Triangle : public Figure
{
protected:
    double a, b, c, A, B, C;

public:

    Triangle(double a, double b, double c, double A, double B, double C) : a(a), b(b), c(c), A(A), B(B), C(C)
    {
        name = "Треугольник";
    }
    void print() override
    {
        cout << endl << name << ":" << endl << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << endl;
    }

};

class RightTriangle : public Triangle
{
public:
    RightTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
    {
        if (C == 90)
            name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle
{

public:
    IsoscelesTriangle(double a, double b, double c, double A, double B, double C) : Triangle(a, b, c, A, B, C)
    {
        if (a == c && A == C)

            name = "Равнобедренный треугольник";

    }
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle(double a, double b, double c, double A, double B, double C) : IsoscelesTriangle(a, b, c, A, B, C)
    {
        if (a == b && A == 60 && B == 60 && C == 60)

            name = "Равносторонний треугольник";
    }
};




class Quadrangle : public Figure
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrangle(double a, double b, double c, double d, double A, double B, double C, double D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D)
    {
        name = "Четырехугольник";
    }
    void print() override
    {
        cout << endl << name << ":" << endl << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }

};

class Rectangle : public Quadrangle
{
public:
    Rectangle(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c && b == d && A == C && B == D)
            name = "Прямоугольник";
    }
};

class Square : public Rectangle
{
public:
    Square(double a, double b, double c, double d, double A, double B, double C, double D) : Rectangle(a, b, c, d, A, B, C, D)
    {
        if (c == b && C && B)
            name = "Квадрат";
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double c, double d, double A, double B, double C, double D) : Quadrangle(a, b, c, d, A, B, C, D)
    {
        if (a == c && b == d && A == C && B == D)

            name = "Параллелограмм";
    }
};

class Rhomb : public Parallelogram
{
public:
    Rhomb(double a, double b, double c, double d, double A, double B, double C, double D) : Parallelogram(a, b, c, d, A, B, C, D)
    {
        if (a == b && b == c && c == d && A == C && B == D)
            name = "Ромб";
    }
};

int main()
{
    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print();

    RightTriangle right_triangle(10, 20, 30, 50, 60, 90);
    right_triangle.print();

    IsoscelesTriangle isosceles_triangle(10, 20, 10, 40, 60, 40);
    isosceles_triangle.print();

    EquilateralTriangle equilateral_triangle(10, 10, 10, 60, 60, 60);
    equilateral_triangle.print();

    Quadrangle quandrangle(10, 20, 30, 40, 50, 60, 70, 80);
    quandrangle.print();

    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    rectangle.print();

    Square square(10, 10, 20, 10, 90, 90, 90, 90);
    square.print();

    Parallelogram parallelogram(10, 20, 10, 20, 30, 40, 30, 40);
    parallelogram.print();

    Rhomb rhomb(30, 30, 30, 30, 30, 40, 30, 40);
    rhomb.print();

    return 0;
}