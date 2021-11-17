#include <stdio.h>


typedef struct Node
{
    int Num;
    struct Node* Next;
}Node;


void main()
{
    Node a;
    Node b;
    a.Num = 1;
    b.Num = 2;

    a.Next = &b;

    printf("%d\n", a.Num);
    //아래둘은 같음
    printf("%d\n", (*a.Next).Num);
    printf("%d\n", a.Next->Num);

    printf("%p\n", a.Next);
    printf("%p\n",&b);
    //->는 (*p).~~와 같다.
    //->는 어떤 값이 있는곳을 가리키다
}

//메모리주소는 32비트
//1바이트는 8 비트 
//메모리주소는 4바이트
//16진수 8자리임
//1바이트는 16진수 두자리로 표기가능

//힙이 동적할당
//스택이 지역
//데어터가 전역
//코드가 코드