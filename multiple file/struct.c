#include<stdio.h>

struct teacher
{
   char name[120];
   struct course
   {
      char course_n[10000];
   } c[10];
}t;
FILE *ft;
int main()
{   int done=0;
    ft=("teacher.txt","ab");
    printf("Enter teacher name:");

    fflush(stdin);
    gets(t.name);
    printf("Enter course number:");
    int n ;
    scanf("%d",n);
    for(int i=0;i<n;i++)
    {
        printf("Enter course name:");
         fflush(stdin);
        gets(t.c[i].course_n);

    };

}
