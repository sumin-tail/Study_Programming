#include <iostream>
using namespace std;

//��ü / ��ü ������ �����ε��� �ۼ� �Ͻÿ�.
//(ex.���������� ū���� ���� ���ְ� ����ó��)

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
    cout << "��ü / ��ü" << endl;
    A.print();
    B.print();
}
