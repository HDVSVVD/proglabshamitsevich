#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Cone {
protected:
    double r;
    double h;
public:
    Cone(double _r = 0, double _h = 0) : r(_r), h(_h) {}
    virtual double BaseArea() { // вычисление площади основания
        return M_PI * r * r;
    }
    virtual double LateralSurfaceArea() { // вычисление боковой поверхности
        return M_PI * r * sqrt(r * r + h * h);
    }
    virtual double TotalSurfaceArea() { // вычисление полной поверхности
        return BaseArea() + LateralSurfaceArea();
    }
    virtual double Volume() { // вычисление объема
        return (1.0 / 3.0) * M_PI * r * r * h;
    }
};

class Truncated_Conus : public Cone {
private:
    double R;
public:
    Truncated_Conus(double _r = 0, double _R = 0, double _h = 0) : Cone(_r, _h), R(_R) {}
    double BaseArea() override { // переопределение метода для вычисления площади основания усеченного конуса
        return M_PI * (r * r + R * R + r * R);
    }
};

int main() {
    const int N = 3; // количество объектов в массиве
    Truncated_Conus arr[N] = { Truncated_Conus(2, 4, 6), Truncated_Conus(3, 5, 7), Truncated_Conus(1, 3, 4) };
    double minWeight = arr[0].Volume() * 7.8; // вес первого объекта в массиве, предполагая, что он сделан из железа
    string minMetal = "Iron"; // металл первого объекта в массиве

    for (int i = 0; i < N; i++) {
        cout << "Object " << i + 1 << endl;
        cout << "Base Area: " << arr[i].BaseArea() << endl;
        cout << "Lateral Surface Area: " << arr[i].LateralSurfaceArea() << endl;
        cout << "Total Surface Area: " << arr[i].TotalSurfaceArea() << endl;
        cout << "Volume: " << arr[i].Volume() << endl;

        string metal;
        cout << "Enter the metal of the object: ";
        cin >> metal;

        double weight = arr[i].Volume() * 7.8; // вычисление веса объекта, предполагая, что плотность железа равна 7.8 г/см^3
        cout << "Weight: " << weight << endl;

        if (weight < minWeight) { // поиск самого легкого объекта
            minWeight = weight;
            minMetal = metal;
        }
    }

    cout << "The lightest object is made of " << minMetal << endl;

    return 0;
}