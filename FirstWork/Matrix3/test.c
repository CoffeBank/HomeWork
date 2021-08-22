#include <stdio.h>
#define N 6

//Заполнить верхний треугольник матрицы 1, а нижний 0

int main()
{
	int A[N][N];
	int b = N - 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (b >= j)
				printf(" %d ", 0);
			else
				printf(" %d ", 1);
		}
		printf("\n");
		b--;
	}
	return 0;
}