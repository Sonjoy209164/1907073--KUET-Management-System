#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct teacher
{
    char name[120];
    char subject[12];
    char date[12];

};
///controller variable declaration
struct teacher teac;

///declaring file pointer in global scope
FILE *fp;
long szt =sizeof(teac);


void admintmodify()
{
    ///storing and processing our choice
    int choice;
    while(1)
    {
        system ("cls");
        printf("            >>>>>>>>>>TEACHER MANAGEMENT SYSTEM<<<<<<<<<<<<\n");
        printf(" MENU\n");
        printf("1.NEW ASSIGN \n");
        printf("2.TEACHER INFO\n");
        printf("3.SEARCH\n");
        printf("4.UPDATE SUBJECT\n");
        printf("5.DELETE INFO\n");

        printf("0.EXIT\n\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        ///choice
        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            inputteacher();
            break;

        case 2:
            displayteacher();
            break;

        case 3:
            searchteacher();
            break;
        case 4:
            updateteacher();
            break;

        case 5:
            delteacher();
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



void inputteacher()
{
    ///fetching date frpm system
    ///sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    /*
    sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    */
    char my_date[12];
    time_t t=time(NULL);
    struct tm tm=*localtime(&teac);
    sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+2000);
    //printf("%s",my_date);
    ///copying my date to struct
    strcpy(teac.date, my_date);



    ///opening file from secondary memory to buffer

    fp=fopen("teacherinfo.txt","ab");
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






    ///writing in the file
    ///fwrite(address of  truct,size of structure, n times,file pointer)
    fwrite(&teac, szt, 1, fp);
    printf("RECORD WAS SAVED SUCCESSFULLY.....\n");
    fclose(fp);




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




////search
void searchteacher()
{
    int ch;
    while(1)
    {
        system("cls");
        printf("**SEARCH**\n");
        printf("1.SEARCH BY NAME\n");
        printf("0.BACK TO MAIN MENU\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 0 :
            main();
            break;
        case 1:
             searchbyname();
            break;


        default :
            printf("INVALID CHOICE\n");

        }

        getch();

    }
}





///SEARCH DATA BY NAME

void searchbyname()
{
    char name[120];
    int f=0;

    printf("ENTER TEACHER'S NAME TO SEARCH: ");
    fflush(stdin);
    gets(name);
    printf("%-30s %-20s %-10s \n","Name", "subject", "date");
    fp=fopen("teacherinfo.txt","rb");
    while(fread(&teac,szt,1,fp)==1)
    {
        ///comparing two string with strcmpi(here i for ignore case) if==returns 0;> 1;<-1;
        if(strcmpi(name,teac.name)==0)
        {
            f=1;
           printf("%-30s %-20s %-10s\n",teac.name, teac.subject, teac.date);
            break;
        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD FOUND.....\n");
}




///updating info
void updateteacher()
{   char name[120];
    int f=0;
    fp=fopen("teacherinfo.txt","rb+");
    printf("ENTER NAME TO UPDATE: ");
   fflush(stdin);
   gets(name);

    while(fread(&teac,szt,1,fp)==1)
    {
        if(strcmpi(name,teac.name)==0)
        {
            f=1;

            char my_date[12];
            time_t t=time(NULL);
            struct tm tm=*localtime(&t);
            sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+2000);
            //printf("%s",my_date);
            ///copying my date to struct
            strcpy(teac.date, my_date);



            ///opening file from secondary memory to buffer


            //if(fp==NULL) printf("FILE CANNOT BE OPENED");
            printf("ENTER TEACHER'S NEW NAME: ");
            fflush(stdin);///empty the input buffer
            //getchar();///this will work fine also
            //scanf("%[^\n]s", str);
            gets(teac.name);
            printf("ENTER NEW SUBJECT: ");
            // getchar();
            fflush(stdin);
            //scanf("%[^\n]s",teac.semester);
            gets(teac.subject);


            ///to take the file pointer 1 step back
            fseek(fp,-szt,1);
            fwrite(&teac,szt,1,fp);
            fclose(fp);
            break;


        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD UPDATED SUCCESSFULLY.....\n");
}



///for deleting teachers info
void delteacher()
{   char name[120];
    int f=0;
    ///temp file
    FILE *ft;
    ft=fopen("tempteac.txt","ab");
    fp=fopen("teacherinfo.txt","rb");
    printf("ENTER NAME TO DELETE: ");
    fflush(stdin);
    gets(name);
     while(fread(&teac,szt,1,fp)==1)
    {
        ///comparing two string with strcmpi(here i for ignore case) if==returns 0;> 1;<-1;
        if(strcmpi(name,teac.name)==0)

        {
            f=1;
        }
        else
        {
            fwrite(&teac,szt,1,ft);
        }
    }
    fclose(ft);
    fclose(fp);

    ///swapping studentinfo with temp
    remove("teacherinfo.txt");
    rename("tempteac.txt","teacherinfo.txt");
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD DELETED SUCCESSFULLY.....\n");
}


///end of admin modify
