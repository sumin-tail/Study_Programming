#include <iostream>
using namespace std;

//객체 / 객체 연산자 오버로딩을 작성 하시오.
//(ex.작은수에서 큰수로 나눌 수있게 예외처리)

class Point {
private:
    int x, y;

public:
    Point(int a, int b) {
        x = a;
        y = b;
    }

    void print() {
        cout << "x = " << x << ", y = " << y << endl;
    }

    Point operator/ (Point tmp);
};

Point Point::operator/ (Point tmp) {

    if (x < tmp.x)
        tmp.x = tmp.x / x;
    else
        tmp.x = x / tmp.x;

    if (y < tmp.y)
        tmp.y = tmp.y /y;
    else
        tmp.y = y / tmp.y;

    return tmp;
}


void main() 
{
    Point A(10, 20);
    Point B(5, 40);
    A.print();
    B.print();
    A = A / B;
    cout << "객체 / 객체" << endl;
    A.print();
    B.print();
}
