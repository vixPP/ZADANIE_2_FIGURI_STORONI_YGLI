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

void print_info(Figure* fig)
{
    fig->print();
}

class Triangle : public Figure
{
protected:
    double a, b, c;
    double A, B, C;

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
    RightTriangle(double a, double b, double c, double A, double B) : Triangle(a, b, c, A, B, 90)
    {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle
{

public:
    IsoscelesTriangle(double a, double b, double A, double B) : Triangle(a, b, a, A, B, A)
    {
            name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(double a) : Triangle(a, a, a, 60, 60, 60)
    {
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

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(double a, double b, double A, double B) : Quadrangle(a, b, a, b, A, B, A, B)
    {
        name = "Параллелограмм";
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double a, double b) : Parallelogram(a, b, 90, 90)
    {
        name = "Прямоугольник";  
    }
};

class Square : public Rectangle
{
public:
    Square(double a) : Rectangle(a, a)
    {
        name = "Квадрат";
    }
};
class Rhomb : public Parallelogram
{
public:
    Rhomb(double a, double A, double B) : Parallelogram(a,a,A,B)
    {
        name = "Ромб";
    }
};

int main()
{
    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print();

    RightTriangle right_triangle(10, 20, 30, 50, 60);
    print_info(&right_triangle);

    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    print_info(&isosceles_triangle);

    EquilateralTriangle equilateral_triangle(30);
    print_info(&equilateral_triangle);

    Quadrangle quandrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&quandrangle);

    Rectangle rectangle(10, 20);
    print_info(&rectangle);

    Square square(10);
    print_info(&square);

    Parallelogram parellelogram(20,30,30,40);
    print_info(&parellelogram);

    Rhomb rhomb(30, 30, 40);
    print_info(&rhomb);

    return 0;
}