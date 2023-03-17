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
    sprintf(my_date, "%02d/%02d/%02d", tm.tm_mday,tm.tm_mon,tm.tm_year+1900);
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
    struct loginstudent stud;

    printf("ENTER USERID: ");
     fflush(stdin);
    gets(stud.username);
    printf("ENTER PASSWORD: ");
    fflush(stdin);
    gets(stud.PASSWORD);
    ///writing info into file
    fwrite(&stud,sizeof(stud),1,logs);
    fclose(logs);



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

        for(int i=0;i<10;i++)
        {
            if(t.c[i].c_code!=0)
                printf("COURSE %d: %s/tCOURSE %d CODE: %d\n",i+1,t.c[i].course,i+1,t.c[i].c_code);
        }
        printf("\n\n\n");
    }

    /*   while(fscanf(fp,"%s %s %s %s",s.name, s.semester, s.roll, s.date )!=EOF)
         {
    printf("%-30s %-20s %-10s %s\n",s.name, s.semester, s.roll, s.date);*/
    fclose(fp);
}


