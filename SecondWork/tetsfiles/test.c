#include <stdio.h>

//Написать программу, которая откроет, закроет, считайет прямо и с конца данные файла 
//Последнее пока нормально не получилось реализовать!

int main()
{
FILE *fp;
char filename[128];
char buff[128];
char stopprog[10] = "stop";
//char read_go[10] = "go";
//char reverse[10] = "reverse";
char whilewant[10];
printf("Введите имя файла для открытия: ");
scanf("%s", &filename);

do 
{
if ((fp = fopen(filename, "r+") )==NULL)
{
    printf ("ERROR_FILE\nSTOP_PROG\n");
}

while(fgets(buff,128,fp)!=NULL)
{
    printf ("%s",buff);
}

printf(">>>");
scanf("%s", whilewant);
}
while (strcmp(whilewant, stopprog) != 0);

close(fp);
return 0;
}