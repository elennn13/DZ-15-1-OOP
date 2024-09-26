#include <iostream>
#include <cmath>

// Базовый абстрактный класс "Уравнение"
//  определяет интерфейс для решения и вывода уравнений.
class Equation {
public:
    virtual double solve() const = 0;
    virtual void print() const = 0;
};

// Класс "Линейное уравнение"
class LinearEquation : virtual public Equation {
private:
    double a, b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}
    // Каждый наследующий класс реализует конкретные методы solve() и print()
    // для решения и вывода линейного и квадратного уравнений соответственно.
    double solve() const override {
        return -b / a;
    }

    void print() const override {
        std::cout << "Линейное уравнение: " << a << "x + " << b << " = 0" << std::endl;
    }
};

// Класс "Квадратное уравнение"
class QuadraticEquation : virtual public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    double solve() const override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0)
            return 0;
        else if (discriminant == 0)
            return -b / (2 * a);
        else {
            double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
            return x1;
        }
    }

    void print() const override {
        std::cout << "Квадратное уравнение: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL,"ru");
    // Пример использования
    LinearEquation linear(2, 4);
    QuadraticEquation quadratic(1, 2, 1);

    std::cout << "Решение линейного уравнения: " << linear.solve() << std::endl;
    linear.print();

    std::cout << "Решение квадратного уравнения: " << quadratic.solve() << std::endl;
    quadratic.print();

    return 0;
}