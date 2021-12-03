#include <iostream>
using namespace std;

template <typename T>
class STACK
{
private:
	T* top; int size;
public:
	STACK(int s) { size = s; top = new T[size]; }
	void push(T a) { *top = a; top++; }
	void pop() { cout << *--top << endl; }
};
void main()
{
	STACK <float> stack(3);
	stack.push(2.2f);
	stack.push(1.1f);
	stack.pop();
	stack.pop();
}
