#include<stdio.h>
///teacher login structure
struct loginteacher
{

    char username[100];
    char passward [20];

};

///teacher login menu

void teacherlogin()
{  printf(">>>>>>>>WELCOME TO TEACHER PANEL<<<<<<<<<\n\n");

     int login=0;
    char username[200],passward[20];
    FILE *logteacher;
    logteacher = fopen("loginteacher.txt","r");
    struct loginteacher teacher;
    printf("ENTER USERID: ");
    scanf("%s",username);
    printf("ENTER PASSWORD: ");
    scanf("%s",passward);
    while(fread(&teacher,sizeof(teacher),1,logteacher))
    {
        if(strcmp(username,teacher.username)==0 && strcmp(passward,teacher.passward)==0)
        {


            printf("LOGIN SUCCESSFUL.....\n");

           teachermenu();
        }
        else login=1;


    }
     if(login==1) printf("INCORRECT USER ID AND PASSWARD.....\n");
    fclose(logteacher);

}


void teachermenu()
{   system("cls");
    int input;

    printf(">>>>>>>>>>>>>>>> TEACHER PANNEL <<<<<<<<<<<<<<<<<<");
    printf("\n\n MENU \n");
    printf("\n1.PROVIDE CLASSTEST MARKS");
    printf("\n2.FIND STUDENT USING FIRST NAME");

    printf("\n3.COUNT OF STUDENTS");
    printf("\n\n0.EXIT\n\n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&input);
    switch(input)
    {
    case 0:
        exit(0);
    case 1:
        providectmarks() ;
        break;
    case 2:
        search();
        break;
    case 3:
         countstud();
        break;


    }

}

}

// provide ct marks

void providectmarks()
{
    printf("PROVIDING CT MARKS");
}


///END OF PROVIDING CT MARKS
void search()
{
    int ch;
    while(1)
    {
        system("cls");
        printf("**SEARCH**\n");
        printf("1.SEARCH BY ROLL\n");
        printf("2.SEARCH BY NAME\n");
        printf("0.BACK TO MAIN MENU\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 0 :
            main();
            break;
        case 1:
            searchbyroll();
            break;

        case 2:
            searchbyname();
            break;

        default :
            printf("INVALID CHOICE\n");

        }

        getch();

    }
}


void searchbyroll()
{
    int roll, f=0;
    fp=fopen("studentinfo.txt","rb");
    printf("ENTER ROLL TO SEARCH: ");
    scanf("%d",&roll);
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    while(fread(&s,sz,1,fp)==1)
    {
        if(roll == s.roll)
        {
            f=1;
            printf("%-30s %-20s %-10d %s\n",s.name, s.semester, s.roll, s.date);
            break;
        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD FOUND.....\n");
}


///SEARCH DATA BY NAME

void searchbyname()
{
    char name[120];
    int f=0;

    printf("ENTER STUDENTT NAME TO SEARCH: ");
    fflush(stdin);
    gets(name);
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    fp=fopen("studentinfo.txt","rb");
    while(fread(&s,sz,1,fp)==1)
    {
        ///comparing two string with strcmpi(here i for ignore case) if==returns 0;> 1;<-1;
        if(strcmpi(name,s.name)==0)
        {
            f=1;
            printf("%-30s %-20s %-10d %s\n",s.name, s.semester, s.roll, s.date);
            break;
        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD FOUND.....\n");
}
///END OF SEARCH AND COUNTING STUDENT

///count student
void countstud()
{
    printf("NUMBER OF STUDENTS: %d\n",countofstud);
}


int main()
{
    teacherlogin();
}
