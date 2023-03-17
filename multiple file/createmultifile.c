#include<stdio.h>

struct student{
char name[30];
char semester[10];
int roll;

}s;
long sz=sizeof(s);

int main()
{

    FILE *fp;
    printf("INPUT VALUES FOR N STUDENTS");
    int n,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        char filename[sizeof "file99.txt"];

        sprintf(filename, "file%02d.txt", i);
        fp = fopen(filename,"ab+");




    ///opening file from secondary memory to buffer


    //if(fp==NULL) printf("FILE CANNOT BE OPENED");
    printf("ENTER STUDENT'S NAME: ");
    fflush(stdin);///empty the input buffer
    //getchar();///this will work fine also
    //scanf("%[^\n]s", str);
    gets(s.name);
    printf("ENTER SEMESTER: ");
    // getchar();
    fflush(stdin);
    //scanf("%[^\n]s",s.semester);
    gets(s.semester);
    printf("ENTER ROLL: ");
    scanf("%d",&s.roll);

    ///enter student id and pass
       printf("********CREATE A NEW STUDENT'S ACCOUNT**********\n");
    FILE *logs;
    ///opening file with pointer
    logs=fopen("loginstudent.txt","ab+");
    if(logs==NULL)
    {
        printf("File does't exsist\n");
        exit(1);
    }

    ///writing in the file
    ///fwrite(address of  truct,size of structure, n times,file pointer)
    fwrite(&s, sz, 1, fp);
    printf("RECORD WAS SAVED SUCCESSFULLY.....\n");
    fclose(fp);




}

    }

