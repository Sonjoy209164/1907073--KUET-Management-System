#include<stdio.h>

struct teacher
{
    char name[120];
    char subject[12];
    char date[12];

};
///controller variable declaration
struct teacher teac;
long szt=sizeof(teac);
///for teacher's login

struct loginteacher
{

    char username[100];
    char passward [20];

};
void inputteacher()
{
    ///fetching date frpm system
    ///sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    /*
    sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    */



    ///opening file from secondary memory to buffer

    FILE *fp;
    printf("INPUT VALUES FOR N STUDENTS");
    int n,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        char filename[sizeof "file99.txt"];

        sprintf(filename, "file%02d.txt", i);
        fp = fopen(filename,"ab+");

   // fp=fopen("teacherinfo.txt","ab");
    //if(fp==NULL) printf("FILE CANNOT BE OPENED");
    printf("ENTER TEACHER's NAME: ");
    fflush(stdin);///empty the input buffer
    //getchar();///this will work fine also
    //scanf("%[^\n]s", str);
    gets(teac.name);
    printf("ENTER SUBJECT: ");
    // getchar();
    fflush(stdin);
    //scanf("%[^\n]s",teac.semester);
    gets(teac.subject);


     ///creating teacher's account

 printf("********CREATE A NEW TEACHER'S ACCOUNT**********\n");
    FILE *logt;
    ///opening file with pointer
    logt=fopen("loginteacher.txt","ab+");
    if(logt==NULL)
    {
        printf("File does't exsist\n");
        exit(1);
    }
    struct loginteacher teacherlog;

    printf("ENTER USERID: ");
     fflush(stdin);
    gets(teacherlog.username);
    printf("ENTER PASSWARD: ");
    fflush(stdin);
    gets(teacherlog.passward);
    ///writing info into file
    fwrite(&teacherlog,sizeof(teacherlog),1,logt);
    fclose(logt);



    ///writing in the file
    ///fwrite(address of  truct,size of structure, n times,file pointer)
    fwrite(&teac, szt, 1, fp);
    printf("RECORD WAS SAVED SUCCESSFULLY.....\n");
    fclose(fp);


    }

}

///displayteacher function
void displayteacher()
{
    system("cls");
    printf("*********TEACHER INFO*************\n");
    ///here for perfectly aligning we used %-30
    printf("%-30s %-20s %-10s \n","Name", "subject", "date");
    //to read file in binary mode
    fp=fopen("teacherinfo.txt","rb");
    while(fread(&teac,szt,1,fp)==1)
    {
        printf("%-30s %-20s %-10s\n",teac.name, teac.subject, teac.date);
    }

    /*   while(fscanf(fp,"%s %s %s %s",teac.name, teac.semester, teac.roll, teac.date )!=EOF)
         {
    printf("%-30s %-20s %-10s %s\n",teac.name, teac.semester, teac.roll, teac.date);*/
    fclose(fp);
}


int main()
{  int d;
    scanf("%d",d);
    switch (d)
    {
    case 1:
        inputteacher();
        break;
    case 2:
        displayteacher();
        break;


    }

}

