#include <iostream>
#include <windows.h>
#include "geometry.h"

using namespace std;

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    cout << "Введіть координати трикутника:" << endl;
    Point A, B, C;
    
    cout << "Точка A:\n x = "; cin >> A.x;
    cout << " y = "; cin >> A.y;
    
    cout << "Точка B:\n x = "; cin >> B.x;
    cout << " y = "; cin >> B.y;
    
    cout << "Точка C:\n x = "; cin >> C.x;
    cout << " y = "; cin >> C.y;

    Triangle t = {A, B, C};
    
    if (t.isDegenerate()) {
        cout << "Трикутник є виродженим!" << endl;
        return 1;
    }

    cout << "\nВиберіть метод перевірки:\n";
    cout << "1 - Метод Герона\n";
    cout << "2 - Метод векторного добутку\n";
    int methodChoice;
    cin >> methodChoice;

    int n;
    cout << "Введіть кількість точок для перевірки: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Point p;
        cout << "\nТочка " << i + 1 << ":\n";
        cout << " x = "; cin >> p.x;
        cout << " y = "; cin >> p.y;

        int result = (methodChoice == 2) ? t.checkPointVector(p) : t.checkPoint(p);
        cout << "Точка (" << p.x << ", " << p.y << ") ";
        
        switch(result) {
            case 0:
                cout << "Не належить трикутнику" << endl;
                break;
            case 1:
                cout << "Лежить на межі трикутника" << endl;
                break;
            case 2:
                cout << "Лежить всередині трикутника" << endl;
                break;
        }
    }

    return 0;
}
