#include<stdio.h>
//if_2��_����
void main()
{
	int time;
	printf("�¸� �̿�ð��� �Է��Ͻÿ� : ");
	scanf("%d", &time);
	if(time<=30)
		printf("%d�� ž�¿�� : %d��", time ,3000);
	else if(time%10 == 0)
		printf("%d�� ž�¿�� : %d��", time, ((time-30)/10)*500+3000 );
	else
		printf("%d�� ž�¿�� : %d��", time, ((time - 30) / 10 * 500) + 3500);

}