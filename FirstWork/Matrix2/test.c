#include <stdio.h>
#define M 15

//вывести заданный массив размером в N в обратном порядке

int main()
{
	int A[20];
	int b;
	for (int i = M; i > 0; i--)
	{
		A[i] = i;
		printf("%d ", A[i]);
	}
	printf ("\n");
	return 0;
}