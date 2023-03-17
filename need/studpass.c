#include<stdio.h>


struct loginstudent
{

    char username[100];
    char passward [20];

};


void register_student()
{
     printf("********CREATE A NEW TEACHER'S ACCOUNT**********\n");
    FILE *logs;
    ///opening file with pointer
    logs=fopen("loginstudent.txt","ab+");
    if(logs==NULL)
    {
        printf("File does't exsist\n");
        exit(1);
    }
    struct loginstudent stud;

    printf("ENTER USERID: ");
     fflush(stdin);
    gets(stud.username);
    printf("ENTER PASSWARD: ");
    fflush(stdin);
    gets(stud.passward);
    ///writing info into file
    fwrite(&stud,sizeof(stud),1,logs);
    fclose(logs);

}

int main()
{
    studentlogin();
    return 0;
}


void studentlogin()
{   int login=0;
    char username[200],passward[20];
    FILE *logstud;
    logstud = fopen("loginstudent.txt","r");
    struct loginstudent student;
    printf("ENTER USERID: ");
    scanf("%s",username);
    printf("ENTER PASSWARD: ");
    scanf("%s",passward);
    while(fread(&student,sizeof(student),1,logstud))
    {
        if(strcmp(username,student.username)==0 && strcmp(passward,student.passward)==0)
        {


            printf("LOGIN SUCCESSFUL.....\n");

           // admintmodify();
        }
        else login=1;


    }
     if(login==1) printf("INCORRECT USER ID AND PASSWARD.....\n");
    fclose(logstud);

}
