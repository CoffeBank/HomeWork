#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//5 агазинов в main задаются их значения
int mal1, mal2, mal3, mal4, mal5;
int f1 = 1, f2 = 1, f3 = 1, f4 = 1, f5 = 1;
int stopme = 0;

//функиция покупателя
void* thread_function(void* arg) {
 int pot = 10000;
 int mat = 1;
 //fprintf(stderr, "child thread pid is %d \n", (int) getpid());
 /* Бесконечный цикл. */
 while (1){
        srand (time(NULL));
        mat = rand()%4+1;
        switch (mat)
        {
        case 1:
            if (f1==1)
            {
                f1 = 0;
                if (pot >= mal1)
                {
                    pot -= mal1;
                    mal1 = 0;
                } else if (pot < mal1)
                {
                    mal1 -= pot;
                    pot = 0;
                }
            } 
            f1 = 1;
            break;
        case 2:
            if (f2==1)
            {
                f2 = 0;
                if (pot >= mal2)
                {
                    pot -= mal2;
                    mal2 = 0;
                } else if (pot < mal2)
                {
                    mal2 -= pot;
                    pot = 0;
                }
            } 
            f2 = 1;
            break;
        case 3:
            if (f3==1)
            {
                f3 = 0;
                if (pot >= mal3)
                {
                    pot -= mal3;
                    mal3 = 0;
                } else if (pot < mal3)
                {
                    mal3 -= pot;
                    pot = 0;
                }
            } 
            f3 = 1;
            break;
        case 4:
            if (f4==1)
            {
                f4 = 0;
                if (pot >= mal4)
                {
                    pot -= mal4;
                    mal4 = 0;
                } else if (pot < mal4)
                {
                    mal4 -= pot;
                    pot = 0;
                }
            } 
            f4 = 1;
            break;
        case 5:
            if (f5==1)
            {
                f5 = 0;
                if (pot >= mal5)
                {
                    pot -= mal5;
                    mal5 = 0;
                } else if (pot < mal5)
                {
                    mal5 -= pot;
                    pot = 0;
                }
            } 
            f5 = 1;
            break;
        }

      if (pot == 0)
      {
          stopme++;
          return NULL;
          
      }
      printf ("my pot = %d\n", pot);
      sleep(20);
  }
 return NULL;
}

void* thread_function_pogr(void* arg){
    int mag;
    while(1)
    {
        srand (time(NULL));
        mag = rand()%4+1;
        switch (mag)
        {
        case 1:
            mal1+=200;
            printf ("now mal1 = %d\n", mal1);
            break;
        case 2:
            mal2+=200;
            printf ("now mal2 = %d\n", mal2);
            break;
        case 3:
            mal3+=200;
            printf ("now mal3 = %d\n", mal3);
            break;
        case 4:
            mal4+=200;
            printf ("now mal4 = %d\n", mal4);
            break;
        case 5:
            mal5+=200;
            printf ("now mal5 = %d\n", mal5);
            break;
        }
        sleep(1);
    }
}

int main() {
 
 srand (time(NULL)); 
 mal1 = rand()%200+900;
 mal2 = rand()%200+900;
 mal3 = rand()%200+900;
 mal4 = rand()%200+900;
 mal5 = rand()%200+900;
 printf ("Колличесвто товара в магазинах изначально: %d %d %d %d %d\n", mal1, mal2, mal3, mal4, mal5);
 pthread_t thread1;
 pthread_t thread2;
 pthread_t thread3;
 pthread_t thread4;
 pthread_t thread5;

 //fprintf(stderr, "main thread pid is %d \n", (int)getpid());
 
 pthread_create(&thread1, NULL, &thread_function, NULL);
 sleep(1);
 pthread_create(&thread2, NULL, &thread_function, NULL);
 sleep(1);
 pthread_create(&thread3, NULL, &thread_function, NULL);
 sleep(1);
 pthread_create(&thread4, NULL, &thread_function_pogr, NULL);

 int main = 1;

 /* Бесконечный цикл. */
  while (main){
      sleep(5);
      if (stopme >=3){
          printf ("\nКонец фильма\n");
          main =0;
      }
      printf ("%d %d %d %d %d\n", mal1, mal2, mal3, mal4, mal5);
  }
 return 0;

}