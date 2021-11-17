#include<stdio.h>
#include<string.h>


int Strcmp(const char* str1, const char* str2)
{
	for (int i = 0; str1[i] != 0 || str2[i] != 0; i++)
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
	}

	return 0;
}

void main()
{
	char str1[10] = "string!!";
	char str2[10] = "string";

	printf("%s == %s : %d\n", str1, str2, Strcmp(str1, str2));
	printf("%s == %s : %d\n", "abc", "Abc", Strcmp("abc", "abc"));
	printf("%s == %s : %d\n", "abc", "def", Strcmp("abc", "def"));
}
