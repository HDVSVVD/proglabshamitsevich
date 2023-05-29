#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
public:
    Time(int _hours = 0, int _minutes = 0) : hours(_hours), minutes(_minutes) {}
    void AddTime(int _hours, int _minutes) { // метод для добавления времени
        hours += _hours;
        minutes += _minutes;
        if (minutes >= 60) { // проверка на переполнение минут
            hours += minutes / 60;
            minutes %= 60;
        }
    }
    int MinutesBetween(Time t) { // метод для вычисления разницы в минутах между двумя моментами времени
        int total1 = hours * 60 + minutes;
        int total2 = t.hours * 60 + t.minutes;
        return abs(total1 - total2);
    }
    void Print() { // метод для вывода времени на экран
        cout << hours << ":" << minutes << endl;
    }
};

int main() {
    Time t1(10, 30);
    Time t2(14, 45);

    t1.Print();
    t2.Print();

    cout << "Minutes between: " << t1.MinutesBetween(t2) << endl;

    t1.AddTime(2, 15);
    t1.Print();

    return 0;
}