#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

class Car {
public:
    string name;
    int position;

    Car(string n) {
        name = n;
        position = 0;
    }

    void move() {
       
        int step = rand() % 6 + 1;
        position += step;
        cout << name << " moves " << step << " steps. Current position: " << position << endl;
    }
};

int main() {
    srand(time(0));

    Car car1("RC Car 1");
    Car car2("RC Car 2");
    Car car3("RC Car 3");

    const int finishLine = 30;
    bool raceOver = false;

    cout << "RC Cars 2003 Race Starts!" << endl;

    while (!raceOver) {
        this_thread::sleep_for(chrono::milliseconds(500)); 
        car1.move();
        car2.move();
        car3.move();

        if (car1.position >= finishLine || car2.position >= finishLine || car3.position >= finishLine) {
            raceOver = true;
        }
    }

    cout << "\nRace Over!" << endl;
    if (car1.position >= finishLine && car2.position >= finishLine && car3.position >= finishLine) {
        cout << "It's a three-way tie!" << endl;
    } else if (car1.position >= finishLine && car2.position >= finishLine) {
        cout << "RC Car 1 and RC Car 2 tie!" << endl;
    } else if (car1.position >= finishLine && car3.position >= finishLine) {
        cout << "RC Car 1 and RC Car 3 tie!" << endl;
    } else if (car2.position >= finishLine && car3.position >= finishLine) {
        cout << "RC Car 2 and RC Car 3 tie!" << endl;
    } else if (car1.position >= finishLine) {
        cout << "RC Car 1 wins!" << endl;
    } else if (car2.position >= finishLine) {
        cout << "RC Car 2 wins!" << endl;
    } else {
        cout << "RC Car 3 wins!" << endl;
    }

    return 0;
}

