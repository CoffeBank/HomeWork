#include <stdio.h>
#define N 5

//Вывести квад матрицу по заданному N

int main()
{
	int b = 1;
	int A[N][N];
	printf(" N=%d\n\n", N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = b;
			b++;
			printf(" %d ", A[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}