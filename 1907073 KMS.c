/*

KUET MANAGEMENT SYSTEM BY 1907073
NAME : SONJOY ROY
ROLL :1907073
DESCRIPTION:
Create Teacher and student Structure : 10min
Admin Panel:
  1.	Login using Function + File  2.	Create Teacher and student account using Function
  3.	Updating Teachers & students Information using Function +  Pointer + File
  4.	Assigning courses to teacher using Function + File

 Teacher�s Panel:

  1.	Login using Function + File
  2.	Provide class test marks using Function+ File: 20 mins + 10 mins
  3.	Find the student by the given first name using Function+ File + pointer
  4.	Count of Students using Function+ File: 30 mins

  Student�s Panel:
  1.	Login using Function+ File
  2.	Check the class test marks using Function+ File

  USED FUNCTION:  1.admintmodify();
                  2.adminmodify();
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


///all structures

///1.structure for admin login
struct login
{
    char fname[100];
    char lname[100];
    int roll;
    char username[100];
    char PASSWORD [20];

};


///2.declaring student structure

struct student
{
    char name[120];
    char semester[12];
    int roll;
    char date[12];
    int ct_marks[100000];
    char username[100];
    char PASSWORD [20];
} s,*ptrs;
///declaring file pointer in global scope
FILE *fp;
long sz =sizeof(s);


///teacher structures
int coursenum;

struct teacher
{
    char name[120];
    char id[15];
    struct Course
    {
        char Coursename[120];
        int c_code;
    } c[10];
    char date[12];
    char username[100];
    char passward [20];
} teac,*u, *ptr;

///declaring file pointer in global scope
FILE *fpt;
long szt =sizeof(teac);

///stud panel edit by admin

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
        printf("7.BACK\n");
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
        case 7:
            choose();
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


/// start login part of admin




void registe()
{
    system("cls");
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
    printf("ENTER PASSWORD: ");
    fflush(stdin);
    gets(l.PASSWORD);
    //scanf("%s",l.PASSWORD);

    ///writing info into file
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\nPRESS ANY KEY TO CONTINUE......");
    getch();
    system("cls");
    adminlogin();

}

void login()
{
    int login=0;
    char username[200],PASSWORD[20];
    FILE *log;
    log = fopen("login.txt","rb");
    struct login l;
    printf("ENTER USERID: ");
    scanf("%s",username);
    printf("ENTER PASSWORD: ");
    scanf("%s",PASSWORD);
    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(PASSWORD,l.PASSWORD)==0)
        {


            printf("LOGIN SUCCESSFUL.....\n");
            choose();
            // admintmodify();
        }
        else login=1;


    }
    if(login==1)
    {
        printf("INCORRECT USER ID AND PASSWORD.....\n");
        printf("PRESS ANY KEY TO CONTINUE.........");
        getch();
        adminlogin();
    }
    fclose(log);


}


int adminlogin()
{
    system("cls");
    int ch;
    printf(">>>>>>>ADMIN PANEL LOGIN<<<<<\n");
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
///end of admin login

void input()
{

    timess();

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

    ///enter student id and pass
    printf("********CREATE A NEW STUDENT'S ACCOUNT**********\n");
    printf("ENTER USERID: ");
    fflush(stdin);
    gets(s.username);
    printf("ENTER PASSWORD: ");
    fflush(stdin);
    gets(s.PASSWORD);
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
        printf("03.BACK");
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
        case 3:
            adminmodify();

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
    printf("PRESS ANY KEY TO CONTINUE......");
    getch();
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
    printf("PRESS ANY KEY TO CONTINUE......");
    getch();
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




void admintmodify()
//int main()
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
        printf("4.UPDATE Course\n");
        printf("5.DELETE INFO\n");

        printf("0.BACK\n\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        ///choice
        switch (choice)
        {
        case 0:
            choose();

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
           // delteacher();
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
    ///sprintf stands for �String print�. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    /*
    sprintf stands for �String print�. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    */

    timess();



    ///opening file from secondary memory to buffer

    fp=fopen("teacherinfo.txt","ab");
    //if(fp==NULL) printf("FILE CANNOT BE OPENED");
    printf("ENTER TEACHER's NAME: ");
    fflush(stdin);///empty the input buffer
    //getchar();///this will work fine also
    //scanf("%[^\n]s", str);
    gets(teac.name);
    // getchar();

    printf("ENTER ID NO: ");
    fflush(stdin);
    gets(teac.id);
    //scanf("%[^\n]s",teac.semester);
    printf("ENTER HOW MANY COURSE TO ASSIGN:");
    int Coursenum=0;
    scanf("%d",&Coursenum);
    int i;
    for(i=0; i<Coursenum; i++)
    {
        printf("ENTER COURSE %d: ",i+1);
        fflush(stdin);
        gets(teac.c[i].Coursename);
        printf("Enter COURSE CODE %d: ",i+1);
        //fflush(stdin);
        scanf("%d",&teac.c[i].c_code);

    }

    teac.c[i].c_code=0;


    ///creating teacher's account

    printf("********CREATE A NEW TEACHER'S ACCOUNT**********\n");
    FILE *logt;

    printf("ENTER USERID: ");
    fflush(stdin);
    gets(teac.username);
    printf("ENTER PASSWARD: ");
    fflush(stdin);
    gets(teac.passward);
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
    printf("%-30s %-20s %-10s \n","NAME", "ID", "DATE");
    //to read file in binary mode
    fp=fopen("teacherinfo.txt","rb");
    while(fread(&teac,szt,1,fp)==1)
    {
        printf("%-30s %-20s %-10s\n",teac.name, teac.id, teac.date);
        for(int i=0; i<10; i++)
        {
            if(teac.c[i].c_code!=0)
                printf("COURSE %d: %s\tCOURSE %d CODE: %d\n",i+1,teac.c[i].Coursename,i+1,teac.c[i].c_code);
        }
        printf("\n\n\n");
    }

}
/*   while(fscanf(fp,"%s %s %s %s",teac.name, teac.semester, teac.roll, teac.date )!=EOF)
     {
printf("%-30s %-20s %-10s %s\n",teac.name, teac.semester, teac.roll, teac.date);
fclose(fp);
}
*/



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
            admintmodify();
            break;
        case 1:
            searchbytname();
            break;


        default :
            printf("INVALID CHOICE\n");

        }

        getch();

    }
}





///SEARCH DATA BY NAME

void searchbytname()
{
    char name[120];
    int f=0;

    printf("ENTER TEACHER'S NAME TO SEARCH: ");
    fflush(stdin);
    gets(name);
    printf("%-30s %-20s %-10s \n","Name", "Id", "Date");
    fp=fopen("teacherinfo.txt","rb");
    while(fread(&teac,szt,1,fp)==1)
    {
        ///comparing two string with strcmpi(here i for ignore case) if==returns 0;> 1;<-1;
        if(strcmpi(name,teac.name)==0)
        {
            f=1;
            printf("%-30s %-20s %-10s\n",teac.name, teac.id, teac.date);
            break;
        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD FOUND.....\n");
}




///updating info

void updateteacher()
{
    FILE *fpt;
    ptr=&teac;
    char name[120];
    int f=0;
    fpt=fopen("teacherinfo.txt","rb+");
    printf("ENTER NAME TO UPDATE: ");
    fflush(stdin);
    gets(name);

    while(fread(ptr,szt,1,fpt)==1)
    {
        if(strcmpi(name,ptr -> name)==0)
        {
            f=1;

            char my_date[12];
            time_t t=time(NULL);
            struct tm tm=*localtime(&teac);
            sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+1900);
            //printf("%s",my_date);
            ///copying my date to struct
            strcpy(ptr ->date, my_date);



            ///opening file from secondary memory to buffer

            fp=fopen("teacherinfo.txt","ab");
            //if(fp==NULL) printf("FILE CANNOT BE OPENED");
            printf("ENTER TEACHER's NAME: ");
            fflush(stdin);///empty the input buffer
            //getchar();///this will work fine also
            //scanf("%[^\n]s", str);
            gets(ptr ->name);
            // getchar();

            printf("ENTER ID NO: ");
            fflush(stdin);
            gets(teac.id);
            //scanf("%[^\n]s",teac.semester);
            printf("ENTER HOW MANY COURSE TO ASSIGN:");
            int Coursenum;
            scanf("%d",&Coursenum);
            for(int i=0; i<Coursenum; i++)
            {
                printf("ENTER COURSE %d: ",i+1);
                fflush(stdin);
                gets(ptr ->c[i].Coursename);
                printf("Enter COURSE CODE %d: ",i+1);
                //fflush(stdin);
                scanf("%d",&ptr ->c[i].c_code);
            }
            printf("********CREATE A NEW TEACHER'S ACCOUNT**********\n");
            FILE *logt;

            printf("ENTER USERID: ");
            fflush(stdin);
            gets(teac.username);
            printf("ENTER PASSWARD: ");
            fflush(stdin);
            gets(teac.passward);



            fseek(fpt,-szt,1);
            fwrite(ptr, szt, 1, fpt);
            fclose(fpt);
            break;

            fclose(logt);



            ///writing in the file
            ///fwrite(address of  truct,size of structure, n times,file pointer)

            printf("RECORD WAS SAVED SUCCESSFULLY.....\n");
            fclose(fp);

        }

    }
    fclose(fp);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD UPDATED SUCCESSFULLY.....\n");
}








///end of admin teacher modify



///for deleting teachers info
/*
void delteacher()
{
    ptr =&teac;
    char name[120];
    int f=0;
    ///temp file
    FILE *ft;
    FILE *up;
    ft=fopen("tempteac.txt","ab");
    up=fopen("teacherinfo.txt","rb");
    printf("ENTER NAME TO DELETE: ");
    fflush(stdin);
    gets(name);
    while(fread(ptr,sizeof(*ptr),1,up)==1)
    {
        ///comparing two string with strcmpi(here i for ignore case) if==returns 0;> 1;<-1;
        if(strcmpi(name,ptr ->name)==0)

        {
            f=1;

        }
        else
        {
            fwrite(ptr,sizeof(*ptr),1,ft);
        }
    }
    fclose(ft);
    fclose(up);

    ///swapping studentinfo with temp
    remove("teacherinfo.txt");
    rename("tempteac.txt","teacherinfo.txt");
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD DELETED SUCCESSFULLY.....\n");
}

*/
/*
void delteacher()
{
     int f=0;
     char name[120];
    ///temp file
    FILE *ft,*fpt;
    ft=fopen("tempt.txt","ab");
    fpt=fopen("teacherinfo.txt","rb");
    printf("ENTER NAME TO DELETE: ");
    fflush(stdin);
    gets(name);

    while(fread(&teac,szt,1,fpt)==1)
    {
        if(strcmpi(name,teac.name)==0)
        {
            f=1;
            remove("teacherinfo.txt");
        }
        else
        {
            fwrite(&teac,szt,1,ft);
        }
    }


    ///swapping studentinfo with temp

      if(!del) printf("deleted");
    rename("tempt.txt","teacher.txt");
     fclose(ft);
    fclose(fpt);
    if(f==0) printf("RECORD NOT FOUND...\n");
    else printf("RECORD DELETED SUCCESSFULLY.....\n");
}

*/





///end of admin teacher modify






///student panel entry
char teacher_id[15],student_roll[15],semester[15],name[25];
struct discipline
{
    char discipline[10];
    int d_code;
} dis[10];




void teacherlogin1()


{
    while(1)
    {

        system("cls");
        printf("*****WELCOME TO TEACHER PANEL LOGIN****\n\n");
        printf("ENTER YOUR USER ID AND PASSWORD\n\n");
        int login=0;
        char username[200],PASSWORD[20];
        FILE *logstud;
        logstud = fopen("teacherinfo.txt","rb");
        printf("ENTER USERID: ");
        scanf("%s",username);
        printf("ENTER PASSWORD: ");
        scanf("%s",PASSWORD);
        while(fread(&teac,sizeof(teac),1,logstud))
        {
            if(strcmp(username,teac.username)==0 && strcmp(PASSWORD,teac.passward)==0)
            {


                printf("LOGIN SUCCESSFUL.....\n");
                strcpy(teacher_id,teac.id);
                strcpy(name,teac.name);
                for(int i=0; i<10; i++)
                {
                    strcpy(dis[i].discipline,teac.c[i].Coursename);
                    dis[i].d_code=teac.c[i].c_code;
                }
                teacher_home();
            }
            else login=1;


        }
        if(login==1) printf("INCORRECT USER ID AND PASSWORD.....\n");
        fclose(logstud);

    }

}


///start of teacher home page
void teacher_home()
{

    int choice;
    while(1)
    {
        system("cls");
        printf("****WELCOME TO TEACHER'S PANEL\n\n");
        printf("1. CT MARKS\n");
        printf("2. UPDATE CT MARKS\n");
        printf("3. SEARCH STUDENT BY ROLL\n");
        printf("4. SEARCH STUDENT BY NAME\n");
        printf("5. COUNT OF STUDENTS\n");
        printf("6. BACK\n");
        printf("7. MAIN MENU\n");
        printf("0. EXIT\n");
        printf("PLEASE ENTER YOUR CHOICE:");

        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(1);
        case 1:
            ct();
            break;
        case 2:
            p_ct();
            break;
        case 3:
            searchbyroll();
            break;
        case 4:
            searchbyname();
            break;
        case 5:
            n_students();
            break;
        case 6:
            teacherlogin1();
            break;
        case 7:
            main();
            break;
        default :
            printf("INVALID CHOICE......");
        }
    }
}


///ct marks display

void ct()
{
    system("cls");
    FILE *fp,*ft;
    ptr=&teac;
    ptrs=&s;
    int n_students=0;
    ft=fopen("teacherinfo.txt","rb+");
    fp=fopen("studentinfo.txt","rb");
    printf("TEACHER'S NAME: %s\n",name);
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    while(fread(ptrs,sizeof(*ptrs),1,fp)==1)
    {
        n_students++;

        printf("%-30s %-20s %-10d %s\n",ptrs ->name, ptrs ->semester, ptrs ->roll, ptrs ->date);
        for(int i=0; i<10; i++)
        {
            if(dis[i].d_code!=0)
                printf("Course Name: %s\tCourse code: %d\tObtained Marks: %d\n",dis[i].discipline,dis[i].d_code,ptrs->ct_marks[dis[i].d_code]);
        }
        printf("\n\n");
    }
    fclose(fp);
    fclose(ft);
    printf("PRESS ANY KEY TO PROCEED.....");
    getch();
}

void p_ct()
{
    system("cls");
    FILE *fp,*ft;
    ptr=&teac;
    ptrs=&s;
    int n_students=0;
    ft=fopen("teacherinfo.txt","rb+");
    fp=fopen("studentinfo.txt","rb");
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    printf("TEACHER'S NAME: %s\n",name);
    while(fread(ptrs,sizeof(*ptrs),1,fp)==1)
    {
        n_students++;

        printf("%-30s %-20s %-10d %s\n",ptrs ->name, ptrs ->semester, ptrs ->roll, ptrs ->date);
        for(int i=0; i<10; i++)
        {
            if(dis[i].d_code!=0)
                printf("Course Name: %s\tCourse code: %d\tObtained Marks: %d\n",dis[i].discipline,dis[i].d_code,ptrs->ct_marks[dis[i].d_code]);
        }
    }
    fclose(fp);
    fclose(ft);
    while(1)
    {

        printf("1. UPDATE/PROVIDE CT MARKS\n");
        printf("2. BACK\n");
        printf("3. MAIN MENU\n");
        printf("0. EXIT\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(0);
        case 1:
            u_p_ct();
            break;
        case 2:
            teacher_home();
            break;
        case 3:
            main();
            break;
        default:
            printf("INVALID CHOICE......\n");
        }
    }
}

void u_p_ct()
{
    FILE *fp;
    fp=fopen("studentinfo.txt","rb+");
    int done=0;
    ptrs=&s;
    char stud_name[120];
    printf("ENTER STUDENT NAME TO MODIFY: ");
    fflush(stdin);
    //scanf("%d",&stud_roll);
    gets(stud_name);
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    while(fread(ptrs,sizeof(*ptrs),1,fp)==1)
    {
        if(strcmp(stud_name, ptrs ->name)==0)
        {
            //stud_roll=ptrs ->roll;
            done=1;
            printf("PREVIOUS MARKS:\n");
            printf("%-30s %-20s %-10d %s\n",ptrs ->name, ptrs ->semester, ptrs ->roll, ptrs ->date);
            for(int i=0; i<10; i++)
            {
                if(dis[i].d_code!=0)
                    printf("Course Name: %s\tCourse code: %d\tObtained Marks: %d\n",dis[i].discipline,dis[i].d_code,ptrs->ct_marks[dis[i].d_code]);
            }

            printf("\n\nProvide/Update marks:\n\n");
            for(int i=0; i<10; i++)
            {
                if(dis[i].d_code!=0)
                {
                    printf("Course Name: %s\tCourse code: %d\tEnter Obtained Marks: ",dis[i].discipline,dis[i].d_code);
                    scanf("%d",&ptrs ->ct_marks[dis[i].d_code]);
                }
            }
            fseek(fp,-sizeof(*ptrs),1);
            fwrite(ptrs,sizeof(*ptrs),1,fp);
            break;
        }
    }
    if(done==0)
    {
        printf("RECORD NOT FOUND.......\n");
        char choice;
        printf("DO YOU WANT TO TRY AGAIN?(y/n): ");
        scanf("%c",&choice);
        if(choice=='y')
        {
            fclose(fp);
            u_p_ct();
        }
    }
    else
        printf("MARKS WAS UPDATED SUCCESSFULLY\n");
    fclose(fp);
    p_ct();
}


/*void void u_p_ct()
{
    system("cls");
    printf(" < UPDATING/PROVIDING CT MARKS >\n");
    int p;
    FILE *tp;
    tp = fopen("Studentinfo.txt","rb+");
    int x;
    printf(" ENTER ROLL TO UPDATE: ");
    scanf("%d",&x);
    fflush(stdin);
     printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    while(fread(&s,sizeof(s),1,tp)==1)
    {
    if( x == s.roll )
        {
            p=1;
            printf(" STUDENT NAME: %s\n SEMESTER: %s\n ROLL: %d\n",s.na, s.cl ,s.rl );
            printf(" PREVIOUS MARKS:\n");
            for(int i=0; i<10; i++)
            {
                if(dis[i].d_code!=0)
                    //printf(" COURSE NAME: %s\tCOURSE CODE: %d\tOBTAINED MARKS: %d\n",crs[i].crsName,crs[i].c_code,s.marks[crs[i].c_code]);
                    printf("%-30s %-20s %-10d %s\n",ptrs ->name, ptrs ->semester, ptrs ->roll, ptrs ->date);
            }
            printf("\n");
            printf(" PROVIDE/UPDATE CT MARKS:\n");
            for(int i=0; i<10; i++)
            {
                if(dis[i].d_code!=0)
                {
                   // printf(" COURSE NAME: %s\tCOURSE CODE: %d\tENTER OBTAINED MARKS: ",crs[i].crsName,crs[i].c_code);
                    //scanf("%d",&s.marks[crs[i].c_code]);
                    printf("Course Name: %s\tCourse code: %d\tEnter Obtained Marks: ",dis[i].discipline,dis[i].d_code);
                    scanf("%d",&ptrs ->ct_marks[dis[i].d_code]);
                }
            }
            fseek(tp,-sizeof(s),1);
            fwrite(&s,sizeof(s),1,tp);
            break;
        }
    }

    if(p==0)
        printf(" WRONG ROLL ENTRY...\n");

    else
        printf(" MARKS UPDATED/PROVIDED SUCCESSFULLY...\n");


    fclose(tp);
    printf(" PRESS ANY KEY TO PROCEED...");
    getch();
    system("cls");
     p_ct();
}


*/



















void n_students()
{
    FILE *fp;
    fp=fopen("studentinfo.txt","rb+");
    int n_students=0;
    while(fread(&s,sizeof(s),1,fp)==1)
    {
        n_students++;
        //printf("d\nName: %s\nRoll: %s\nClass: %s\nUser Name: %s\n\n\n",n_s,s.name_s,s.roll,s.Class,s.u_name);
    }
    printf("NUMBER OF STUDENTS: %d\n\n",n_students);
    printf("\nPRESS ANY KEY.......\n");
    fclose(fp);
    getch();

}

void studentlogin()
{
    int login=0;
    ptrs=&s;
    char username[200],PASSWORD[20];
    FILE *logstud;
    logstud = fopen("studentinfo.txt","r");

    printf("ENTER USERID: ");
    scanf("%s",username);
    printf("ENTER PASSWORD: ");
    scanf("%s",PASSWORD);
    while(fread(&s,sizeof(s),1,logstud))
    {
        if(strcmp(username,s.username)==0 && strcmp(PASSWORD,s.PASSWORD)==0)
        {
            login=0;
            strcpy(name,s.name);
            strcpy(semester,s.semester);
            printf("LOGIN SUCCESSFUL.....\n");
            s_hpage();

        }
        else login=1;


    }
    if(login==1)
    {
        printf("INCORRECT USER ID AND PASSWORD.....\n");
        studentlogin();
    }
    fclose(logstud);

}



void s_hpage()
{
    int choice;
    while(1)
    {

        printf("1. CHECK MARKS\n");
        printf("2. BACK\n");
        printf("3. MAIN MENU\n");
        printf("0. EXIT\n");
        printf("PLEASE ENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 0:
            exit(0);
        case 1:
            c_marks();
            break;
        case 2:
            studentlogin();
            break;
        case 3:
            main();
            break;
        }
    }
}


void c_marks()
{
    system("cls");
    int n_students=0,i=0;
    FILE *fp,*ft;
    fp=fopen("studentinfo.txt","rb");
    ft=fopen("teacherinfo.txt","rb");
    // printf("Name: %s\nRoll: %s\nClass: %s\n\n\n",name,student_roll,semester);
    printf("%-30s %-20s %-10s %s\n","Name", "semester", "roll", "date");
    printf("%-30s %-20s %-10d %s\n",s.name, s.semester, s.roll, s.date);
    while(fread(&teac,sizeof(teac),1,ft)==1)
    {
        while(fread(&s,sizeof(s),1,fp)==1)
        {

            if(strcmp(name,s.name)==0)
            {
                for(int i=0; i<10; i++)
                {
                    dis[i].d_code=teac.c[i].c_code;
                    if(dis[i].d_code!=0)
                        printf("%d. COURSE %s\n MARKS:%d\n\n",++n_students,teac.c[i].Coursename,s.ct_marks[dis[i].d_code]);
                }
                fseek(fp,-sizeof(s),SEEK_CUR);
                break;
            }
        }
    }
    fclose(ft);
    fclose(fp);
    getch();
}

///MAIN FUNCTION
int main()
{
    int input;

    printf(">>>>>>>>>>>>>>>>  KUET MANAGEMENT SYSTEM BY 1907073 <<<<<<<<<<<<<<<<<<");
    printf("\n\n MENU \n");
    printf("\n1.ADMIN PANEL");
    printf("\n2.TEACHER'S PANEL");
    printf("\n3.STUDENT'S PANEL");
    printf("\n\n0.EXIT\n\n");

    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&input);

    switch(input)
    {
    case 0:
        exit(0);
    case 1:
        adminlogin();
        break;
    case 2:
        teacherlogin1();
        break;
    case 3:
        studentlogin();
        break;


    }

}

///after successful login of admin let him choose whom to edit
void choose()
{
    system("cls");
    int n;
    printf("*****MENU*****\n");

    printf("1.TEACHER PANEL \n");
    printf("2.STUDENT PANEL \n");
    printf("0.BACK TO MAIN MENU \n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&n);
    while(1)
    {
        switch(n)
        {
        case 1:
            admintmodify();
            break;
        case 2:
            adminmodify();
            break;
        case 0:
            main();
            break;
        default :
            printf("INVALID CHOICE...");
            break;
        }
    }

}

void timess()
{
    ///fetching date frpm system
    ///sprintf stands for �String print�. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    /*
    sprintf stands for �String print�. Instead of printing on console, it store output on char buffer which are specified in sprintf.
    */
    char my_date[12];
    time_t t=time(NULL);
    struct tm tm=*localtime(&t);
    sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+1900);
    strcpy(s.date, my_date);
    strcpy(teac.date, my_date);
    strcpy(teac.date, my_date);
}




