// Фигуры. Методы.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Figure {
private:
    std::string name;
    int sides_count;

public:
    Figure(int sides_count) {
        set_name("Фигура");
        this-> sides_count = sides_count;
    }

    void set_name(std::string name) { this->name = name; }
    int get_sides_count() { return sides_count; }
    std::string get_name() { return name; }

    bool virtual criterion() {
        if (get_sides_count() == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    void virtual print() {
        std::cout << get_name() << ":" << std::endl;
        if (criterion() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
        std::cout << std::endl;
    }
};

class Triangle : public Figure {
private:
    int a, b, c, A, B, C;

public:
    Triangle(int sides_count, int a, int b, int c, int A, int B, int C):Figure(sides_count) {
        set_name("Треугольник");
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }

    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }

    bool criterion() override {
        if (get_sides_count() == 3 && (get_A() + get_B() + get_C()) == 180) {
            return true;
        }
        else {
            return false;
        }
    }

    void print() override {
        std::cout << get_name() << ":" << std::endl;
        if (criterion() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
        std::cout << "Стороны: a = " << get_a() << " d = " << get_b() << " c = " << get_c() << std::endl;
        std::cout << "Углы: A = " << get_A() << " B = " << get_B() << " C = " << get_C() << std::endl;
        std::cout << std::endl;
    }
};

class Right_triangle : public Triangle {
public:
    Right_triangle(int sides_count, int a, int b, int c, int A, int B, int C) : Triangle(sides_count, a, b, c, A, B, C) {
        set_name("Прямоугольный треугольник");
    }

    bool criterion() override {
        if (get_sides_count() == 3 && get_C() == 90) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Isosceles_riangle : public Triangle {
public:
    Isosceles_riangle(int sides_count, int a, int b, int c, int A, int B, int C) : Triangle(sides_count, a, b, c, A, B, C) {
        set_name("Равнобедренный треугольник");
    }

    bool criterion() override {
        if (get_sides_count() == 3 && get_a() == get_c() && get_A() == get_C()) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int sides_count, int a, int b, int c, int A, int B, int C) : Triangle(sides_count, a, b, c, A, B, C) {
        set_name("Равносторонний треугольник");
    }

    bool criterion() override {
        if (get_sides_count() == 3 && get_a() == get_b()  == get_c() && (get_A() == get_B() == get_C()) == 60) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Quadrilateral :public Figure {
private:
    int a, b, c, d, A, B, C, D;

public:
    Quadrilateral(int sides_count, int a, int b, int c, int d, int A, int B, int C, int D):Figure(sides_count) {
        set_name("Четырёхугольник");
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }

    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }

    bool criterion() override {
        if (get_sides_count() == 4 && (get_A() + get_B() + get_C() + get_D()) == 360) {
            return true;
        }
        else {
            return false;
        }
    }

    void print() override {
        std::cout << get_name() << ":" << std::endl;
        if (criterion() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_sides_count() << std::endl;
        std::cout << "Стороны: a = " << get_a() << " d = " << get_b() << " c = " << get_c() << " d = " << get_d() << std::endl;
        std::cout << "Углы: A = " << get_A() << " B = " << get_B() << " C = " << get_C() << " D = " << get_D() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int sides_count, int a, int b, int c, int d, int A, int B, int C, int D) :Quadrilateral(sides_count, a, b, c, d, A, B, C, D){
        set_name("Параллелограмм");
    }

    bool criterion() override {
        if (get_sides_count() == 4 && get_A() == get_C() && get_B() == get_D() && get_a() == get_c() && get_b() == get_d()) {
            return true;
        }
        else {
            return false;
        }
    }

};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int sides_count, int a, int b, int c, int d, int A, int B, int C, int D) :Quadrilateral(sides_count, a, b, c, d, A, B, C, D) {
        set_name("Прямоугольник");
    }

    bool criterion() override {
        if (get_sides_count() == 3 && get_a() == get_c() && get_b() == get_d() && (get_A() == get_B() == get_C() == get_D()) == 90) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Rhomb : public Quadrilateral {
public:
    Rhomb(int sides_count, int a, int b, int c, int d, int A, int B, int C, int D) :Quadrilateral(sides_count, a, b, c, d, A, B, C, D) {
        set_name("Ромб");
    }

    bool criterion() override {
        if (get_sides_count() == 4 && get_a() == get_b() == get_c() == get_d() && get_A() == get_C() && get_B() == get_D()) {
            return true;
        }
        else {
            return false;
        }
    }

};

class Square : public Quadrilateral {
public:
    Square(int sides_count, int a, int b, int c, int d, int A, int B, int C, int D) :Quadrilateral(sides_count, a, b, c, d, A, B, C, D) {
        set_name("Квадрат");
    }

    bool criterion() override {
        if (get_sides_count() == 4 && get_a() == get_b() == get_c() == get_d() && (get_A() == get_C() == get_B() == get_D()) == 90) {
            return true;
        }
        else {
            return false;
        }
    }
};


void print(Figure* figure) { figure->print(); }


int main() {
    setlocale(LC_ALL, "ru");

    Triangle triangle(3, 10, 20, 30, 60, 60, 60);
    Right_triangle right_triangle(3, 10, 20, 30, 40, 50, 90);
    Isosceles_riangle isosceles_riangle(3, 10, 20, 30, 40, 50, 60);
    Equilateral_triangle equilateral_triangle(3, 10, 20, 30, 40, 50, 60);
    Quadrilateral quadrilateral(4,10,20,30,40,50,60,70,80);
    Rectangle rectangle(4, 10, 20, 30, 40, 50, 60, 70, 80);
    Square square(4, 10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(4, 10, 20, 30, 40, 50, 60, 70, 80);
    Rhomb rhomb(4, 10, 20, 30, 40, 50, 60, 70, 80);
    
    print(&triangle);
    print(&right_triangle);
    print(&isosceles_riangle);
    print(&equilateral_triangle);
    print(&quadrilateral);
    print(&rectangle);
    print(&square);
    print(&parallelogram);
    print(&rhomb);
}