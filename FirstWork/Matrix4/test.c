#include <stdio.h>
#define N 9

//Заполнить матрицу числами от 1 до N^2 улиткой 

int main()
{
	int A[N][N];
	Num(A);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//функция записи по спирали в массив
int Num(int a[N][N])
{
	int b = 1, f1 = 0, f2 = 0;
	int gp = 0;
	int point1 = N - 1;
	int point2 = N;
	int q1 = N - 1;
	int q2 = N - 1;
	int q3 = 0;
	int pog = 0;
	int los1 = 0;
	int los2 = 0;
	int row1 = 0;
	int row2 = 0;

	for (int i = 0; b != N*N+1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//эти два if приращивают j так, чтобы он имел колличество циклов в последовательности N, N-1, N-1, N-2, N-2 и тд до 1, 1
			if ((i % 2 != 0 && f1 == 1 && f2 == 0 && los1 == 0) || (i % 2 != 0 && f1 == 0 && f2 == 1 && los1 == 0))
			{
				
				j+= gp;
				los1 = 1;
			}
			else if ((i % 2 == 0 && f1 == 1 && f2 == 1 && los2 == 0) || (i % 2 == 0 && f1 == 0 && f2 == 0 && los2 == 0))
			{
				j += gp;
				gp++;
				los2 = 1;
			} 

			//следующие четыре if пишут в свих напрвлениях
			//слево на право
			if (i % 2 == 0 && f1 == 0)
			{
				a[row1][j-row2] = b;
				b++;
				if (j == N - 1)
				{
					f1 = 1;
					row1++;
					row2++;
				}
					
			}
			//сверху в низ
			else if (i % 2 != 0 && f2 == 0)
			{
				
				a[j-pog][q1] = b;
				b++;
				if (j == N - 1)
				{
					f2 = 1;
					q1--;
					pog++;
				}
			}
			//справо на лево
			else if (i % 2 == 0 && f1 != 0)
			{
				a[q2][point1-j] = b;
				b++;
				if (j == N - 1)
				{
					f1 = 0;
					q2--;
					point1++;
				}
					
			}
			//снизу в верх
			else if (i % 2 != 0 && f2 != 0)
			{
				a[point2 - j][q3] = b;
				b++;
				if (j == N - 1)
				{
					f2 = 0;
					q3++;
					point2++;
				}
					
			}
			//сбрасывет флаги для первых двух if в цикле
			if (j == N - 1)
			{
				los1 = 0;
				los2 = 0;
			}
		}
	}
	return a;
}