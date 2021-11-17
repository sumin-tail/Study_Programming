#include <stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>

//재귀함수를 이용하여 연결 리스트를 구현할 것
//들어가야 할 기능은 삽입, 삭제, 검색, 수정
//마지막에 종료하면 할당 추는 것 잊지 않기
//삭제, 수정 함수에서 검색 함수 이용하기

//학생 정보를 담을 리스트 구현
typedef struct Student
{
    char name[10]; //이름
    int age; //나이
    char address[30]; //주소
    //국영수 점수
    int korean;
    int math;
    int english;
    struct Student* link; 
}Student;

//메뉴
void Menu()
{
    printf("< < < = = = = 메뉴 = = = = > > >\n");
    printf("1.학생 등록\n");
    printf("2.학생 검색\n");
    printf("3.학생 목록\n");
    printf("4.학생 수정\n");
    printf("5.학생 삭제\n");
    printf("6.종료\n");
    printf("====================\n");
    printf("선택 : ");
}

//전체 할당 해제
void Release(Student* Node)
{
    if (Node == NULL) //Node 가 NULL인지 확인
    {
        return;
    }//NODE가 NULL == 리턴 해서 돌아간 구조체가 가장 처음에 추가된 구조체라는 것
    Release(Node->link);//Node 가 NULL이 될 때까지 재귀함수로 아래로 내려감
    //리턴으로 나오면 가장 아래부터 위까지 차례로 할당 해제됨
    free(Node);//가장 마지막 구조체 할당 해제
}

//검색 함수 > 있으면 주소반환 없으면 NULL을 반환
Student* Search(Student* Node, char name[])
{
    if (Node == NULL)// 끝까지 왔는데도 찾지못했다면
    {
        return NULL;
    }

    if (strcmp (Node->name , name) == 0 )//이름이 같은 정보를 찾으면 주소를 돌려줌
    {
        printf("학생 정보 검색 완료\n");
        return Node;
    }

    return Search(Node->link, name);//해당노드에 없으면 다음노드로 건너감
}

//학생 정보 출력
void Student_Information(Student* Node)
{
    if (Node == NULL)
    {
        printf("검색하고자 하는 학생이 존재하지 않습니다.\n");
        return;
    }

    int max = Node->korean + Node->english + Node->math; //합계점수
    float average = (float)max / 3;
    char rank;
    if (average >= 90)
    {
        rank = 'A';
    }
    else if (average >= 80)
    {
        rank = 'B';
    }
    else if (average >= 70)
    {
        rank = 'C';
    }
    else if (average >= 60)
    {
        rank = 'D';
    }
    else
    {
        rank = 'F';
    }

    printf("< < = = = = = Information = = = = = > >\n");
    printf("학생 이름 : %s\n", Node->name);
    printf("학생 나이 : %d 세\n", Node->age);
    printf("학생 주소 : %s\n", Node->address);
    printf("국어 점수 : %d 점\n", Node->korean);
    printf("영어 점수 : %d 점\n", Node->english);
    printf("수학 점수 : %d 점\n", Node->math);
    printf("합계 점수 : %d 점\n", max);
    printf("평균 점수 : %.2f 점\n", average);
    printf("학생 등급 : %c 등급\n", rank);

}

//학생 전체 출력
void All_Student_Print(Student* Node)
{
    if (Node == NULL)
    {
        return;
    }
    printf("\t  %s", Node->name);
    printf("\t%d", Node->age);
    printf("\t\t%s\n", Node->address);
    All_Student_Print(Node->link);
}

//학생추가 - 헤더를 항상 갱신한다 > 가장 첫번째가 될 노드주소를 항상 반환
Student* Student_Add(Student* Node)
{
    if (Node == NULL) //현재노드가 눌일경우
    {
        //새 동적할당하고 주소저장
        Student* add = (Student*)malloc(sizeof(Student));
        add->link = NULL;

        //학생정보입력
        system("cls");
        printf("학생 이름 입력 : ");
        scanf("%s", add->name);
        printf("%s 학생 나이 입력 : ", add->name);
        scanf("%d", &add->age);
        printf("%s 학생 주소 입력 : ", add->name);
        scanf("%s", add->address);
        printf("%s 학생 국어 점수 : ", add->name);
        scanf("%d", &add->korean);
        printf("%s 학생 영어 점수 : ", add->name);
        scanf("%d", &add->english);
        printf("%s 학생 수학 점수 : ", add->name);
        scanf("%d", &add->math);
        printf("학생 정보 입력 완료\n");
        //끝까지 가서 새로 만든 학생의 주소를 들고 돌아온다. 
        return add; //만약 이게 만들어지는 첫번째일 경우 그래도 헤드가 가리키게되고     
    }
    //아니라면 그전 노드의 링크를 갱신시켜준다.

    Node->link = Student_Add(Node->link);//재귀함수
    return Node;
}

//학생 수정
void Student_Retouch(Student* Node)
{
    int select = 0;
    int data;
    char change[30];

    if (Node == NULL)//해당학생이 없다는 뜻이니 리턴
    {
        printf("찾는 학생이 없습니다.\n");
        return;
    }

    while (select !=5)
    {
        system("cls");
        Student_Information(Node);// 학생 정보를 출력
        printf("\n");
        printf("수정할 항목을 선택 하시오\n");
        printf("1.이름 2.나이 3.주소 4.점수 5.수정종료\n");
        printf("선택 : ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("현재 이름 : %s\n", Node->name);
            printf("수정할 이름 : ");
            scanf("%s", &change);
            printf("%s -> %s 로 이름 수정 완료\n", Node->name , change);
            strcpy(Node->name, change); //문자열은 대입이 안되니 strcpy 사용
            system("pause");
            break;
        case 2:
            printf("현재 나이 : %d 세\n", Node->age);
            printf("수정할 나이 :    세");
            printf("\b\b\b\b\b\b");
            scanf("%d", &data);
            printf("%d 세 -> %d 세 로 나이 수정 완료\n", Node->age, data);
            Node->age = data;
            system("pause");
            break;
        case 3:
            printf("현재 주소 : %d \n", Node->address);
            printf("수정할 주소 : ");
            scanf("%s", &change);
            printf("%s -> %s 로 주소 수정 완료\n", Node->address, change);
            strcpy(Node->address, change); //문자열
            system("pause");
            break;
        case 4:
            printf("현재 점수\n");
            printf("국어 : %d 영어 : %d 수학 : %d\n", Node->korean, Node->english, Node->math);
            printf("수정할 국어 점수 : ");
            scanf("%d", &data);
            Node->korean = data;
            printf("수정할 영어 점수 : ");
            scanf("%d", &data);
            Node->english = data;
            printf("수정할 수학 점수 : ");
            scanf("%d", &data);
            Node->math = data;
            printf("점수 수정 완료\n");
            system("pause");
            break;
        case 5:
            printf("수정을 종료합니다.\n");
            system("pause");
            break;
        }
    }
   
}

//학생 삭제 - 학색 추가처럼 조건 없애기
Student* Student_Delete(Student* Node, char name[])
{
    //서칭 구간~
    if (Node == NULL)// 다음 노드가 끝일경우
    {
        return Node;
    }

    //삭제할 노드에 도착하면 다음노드의 주소를 리턴 <
    if (strcmp(Node->name, name) == 0)//삭제할 노드를 찾으면
    {
        Student* tmp; //포인터
        tmp = Node->link;// 삭제할 노드 다음노드의 주소를 담고
        free(Node);//현재노드의 주소 할당해제
        printf("삭제 완료\n");
        system("pause");
        return tmp;//삭제할 노드 앞쪽 링크에 담을 다음노드 주소 tmp를 보내줌
    }

    Node->link = Student_Delete(Node->link, name); //해당노드에 없으면 다음노드로 건너감
    return Node; //리턴 잊지않기
    //~서칭 구간
}

void main()
{
    int select;
    int num;
    char searchname[10];
    int count = 0;
    Student* Head = NULL; //머리

    while (1)
    {
        system("cls");
        Menu();
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            Head = Student_Add(Head);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("검색할 이름 입력 : ");
            scanf("%s", searchname);
            Student_Information(Search(Head, searchname));
            system("pause");
            break;
        case 3:
            system("cls");
            printf("< < = = = = = Information = = = = = > >\n");
            printf("\n");
            printf("\t학생이름\t학생나이\t학생주소\n");
            All_Student_Print(Head);
            printf("<학생 개개인의 점수는 검색을 이용하세요!!>\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("수정할 학생 이름은? ");
            scanf("%s", searchname);
            Student_Retouch(Search(Head, searchname));
            break;
        case 5:
            system("cls");
            if (Head == NULL)
            {
                printf("아무런 데이터가 없습니다.\n");
                system("pause");
                break;
            }
            printf("삭제할 학생 이름: ");
            scanf("%s", searchname);
            Head = Student_Delete(Head, searchname); //헤드갱신
            break;
        case 6:
            Release(Head);
            printf("할당 해제 완료");
            return;
        }
    }

}