#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("WELCOME TO TEACHER'S PANEL......")
    Printf("")
}
///teacher login

struct login
{
    char fname[100];
    char lname[100];
    int roll;
    char username[100];
    char passward [20];

};

void registe()
{    system("cls");
     printf("********CREATE A NEW ACCOUNT**********\n");
    FILE *log;
    ///opening file with pointer
    log=fopen("login.txt","ab+");
    if(log==NULL)
    {
        printf("File does't exsist\n");
        exit(1);
    }
    struct login l;
    printf("ENTER FIRST NAME: ");
    fflush(stdin);
    gets(l.fname);
    //scanf("%s",l.fname);
    printf("ENTER LAST NAME: ");
    fflush(stdin);
    gets(l.lname);
    //scanf("%s",l.lname);
   /// printf("ENTER ROLL: ");
   /// scanf("%d",&l.roll);
    printf("ENTER USERID: ");
     fflush(stdin);
    gets(l.username);
    //scanf("%s",l.username);
    printf("ENTER PASSWARD: ");
    fflush(stdin);
    gets(l.passward);
   //scanf("%s",l.passward);

    ///writing info into file
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\nPRESS ANY KEY TO CONTINUE......");
    getch();
    system("cls");
    adminlogin();

}

void login()
{   int login=0;
    char username[200],passward[20];
    FILE *log;
    log = fopen("login.txt","r");
    struct login l;
    printf("ENTER USERID: ");
    scanf("%s",username);
    printf("ENTER PASSWARD: ");
    scanf("%s",passward);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(passward,l.passward)==0)
        {


            printf("LOGIN SUCCESSFUL.....\n");
           adminmodify();

        }
        else login=1;


    }
     if(login==1) printf("INCORRECT USER ID AND PASSWARD.....\n");
    fclose(log);


}


int adminlogin()
{
    int ch;
    printf("MENU: \n");
    printf("1.REGISTER A NEW ACCOUNT \n");
    printf("2.LOGIN \n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&ch);

   {
       switch(ch)
    {
    case 0:
        exit(0);
    case 1:
        registe();
        break;
    case 2:
        login();
        break;
    default :
        printf("INVALID CHOICE.....\N");
        break;
    }

   }

    return 0;
}
///end of teacher login







void adminmodify()
{
    ///storing and processing our choice
    int choice;
    while(1)
    {
        system ("cls");
        printf("            >>>>>>>>>>KUET MANAGEMENT SYSTEM<<<<<<<<<<<<\n");
        printf(" MENU\n");
        printf("1.NEW ADMISSION \n");
        printf("2.STUDENT INFO \n");
        printf("3.SEARCH\n");
        printf("4.UPDATE INFO\n");
        printf("5.DELETE INFO\n");
        printf("6.SORT\n\n");
        printf("0.EXIT\n\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        ///choice
        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            input();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;
        case 4:
            update();
            break;

        case 5:
            del();
            break;

        case 6:
            sort();
            break;

        default :
           {
               printf("PLEASE MAKE A VALID CHOICE.\n");

           }
        }
        printf("PRESS ANY KEY TO CONTINUE.........\n");
        getch();
    }
    return 0;
}



void input()
{
    ///fetching date frpm system
    ///sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    /*
    sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    */
    char my_date[12];
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+2000);
    //printf("%s",my_date);
    ///copying my date to struct
    strcpy(s.date, my_date);



    ///opening file from secondary memory to buffer

    fp=fopen("studentinfo.txt","ab");
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





    ///writing in the file
    ///fwrite(address of  truct,size of structure, n times,file pointer)
    fwrite(&s, sz, 1, fp);
    printf("RECORD WAS SAVED SUCCESSFULLY.....\n");
    fclose(fp);




}

///display function
void display()
{
    system("cls");
    printf("**********STUDENT INFO*************\n");
    ///here for perfectly aligning we used %-30
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    //to read file in binary mode
    fp=fopen("studentinfo.txt","rb");
    while(fread(&s,sz,1,fp)==1)
    {
        printf("%-30s %-20s %-10d %s\n",s.name, s.semester, s.roll, s.date);
    }

    /*   while(fscanf(fp,"%s %s %s %s",s.name, s.semester, s.roll, s.date )!=EOF)
         {
    printf("%-30s %-20s %-10s %s\n",s.name, s.semester, s.roll, s.date);*/
    fclose(fp);
}




////search
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

void update()
{
    int roll, f=0;
    fp=fopen("studentinfo.txt","rb+");
    printf("ENTER ROLL TO UPDATE: ");
    scanf("%d",&roll);

    while(fread(&s,sz,1,fp)==1)
    {
        if(roll == s.roll)
        {
            f=1;

            char my_date[12];
            time_t t=time(NULL);
            struct tm tm=*localtime(&t);
            sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+2000);
            //printf("%s",my_date);
            ///copying my date to struct
            strcpy(s.date, my_date);



            ///opening file from secondary memory to buffer


            //if(fp==NULL) printf("FILE CANNOT BE OPENED");
            printf("ENTER STUDENT'S NEW NAME: ");
            fflush(stdin);///empty the input buffer
            //getchar();///this will work fine also
            //scanf("%[^\n]s", str);
            gets(s.name);
            printf("ENTER NEW SEMESTER: ");
            // getchar();
            fflush(stdin);
            //scanf("%[^\n]s",s.semester);
            gets(s.semester);
            printf("ENTER NEW ROLL: ");
            scanf("%d",&s.roll);

            ///to take the file pointer 1 step back
            fseek(fp,-sz,1);
            fwrite(&s,sz,1,fp);
            fclose(fp);
            break;


        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD UPDATED SUCCESSFULLY.....\n");
}

void del()
{
    int roll, f=0;
    ///temp file
    FILE *ft;
    ft=fopen("temp.txt","ab");
    fp=fopen("studentinfo.txt","rb");
    printf("ENTER ROLL TO DELETE: ");
    scanf("%d",&roll);

    while(fread(&s,sz,1,fp)==1)
    {
        if(roll == s.roll)
        {
            f=1;
        }
        else
        {
            fwrite(&s,sz,1,ft);
        }
    }
    fclose(ft);
    fclose(fp);

    ///swapping studentinfo with temp
    remove("studentinfo.txt");
    rename("temp.txt","studentinfo.txt");
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD DELETED SUCCESSFULLY.....\n");
}



///sorting

void sort()
{

    int c=0,i,j;
    struct student s1[50],t;
    system("cls");
    printf("**********SORT BY ROLL*************\n");
    ///here for perfectly aligning we used %-30
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    //to read file in binary mode
    fp=fopen("studentinfo.txt","rb");
    while(fread(&s,sz,1,fp)==1)
    {
        s1[c++] =s;
    }
    for(i=0; i<c-1; i++)
    {
        for(j=i+1; j<c; j++)
        {
            if(s1[i].roll > s1[j].roll)
            {
                t = s1[i];
                s1[i] = s1[j];
                s1[j] = t;
            }
        }

    }

    for(i=0; i<c; i++)  printf("%-30s %-20s %-10d %s\n",s1[i].name, s1[i].semester, s1[i].roll, s1[i].date);

    fclose(fp);
}

///end of admin modify
