
struct studentloginl{
        char fname[30];
        char lname[30];
        int roll;
        char userId[30];
        char password[100];
    }studentl;

    void registe2(){
        printf("****Create a new account*****\n");
        FILE *log2;
        //opening file with pointer
        log2=fopen("login2.txt","ab+");
        if(log2==NULL)
    {
        printf("File does't exsist\n");
        exit(1);
    }
    printf("ENTER FIRST NAME: ");
    fflush(stdin);
    gets(studentl.fname);
    //scanf("%s",studentl.fname);
    printf("ENTER LAST NAME: ");
    fflush(stdin);
    gets(teacherl.lname);
    //scanf("%s",studentl.lname);
    printf("ENTER roll: ");
    scanf("%d",&studentl.roll);
    printf("ENTER USERID: ");
    fflush(stdin);
    gets(studentl.userId);
    //scanf("%s",studentl.userId);
    printf("ENTER PASSWORD: ");
    fflush(stdin);
    gets(studentl.password);
    //scanf("%s",studentl.password);
    // writing info in the file
    fwrite(&studentl,sizeof(studentl),1,log2);
    fclose(log2);
    printf("Press any key to continue......");
    getch();
    system("cls");
    studentlogin();
    }
    void login2(){
    int login=0;
    char userId[200],password[20];
    FILE *log2;
    log2 = fopen("login2.txt","r");
    printf("ENTER USERID: ");
    scanf("%s",userId);
    printf("ENTER PASSWORD: ");
    scanf("%s",password);
    while(fread(&studentl,sizeof(studentl),1,log2))
    {
        if(strcmp(userId,studentl.userId)==0 && strcmp(password,studentl.password)==0)
        {


            printf("LOGIN SUCCESSFUL.....\n");
            //teachermodify();

        }
        else printf("INCORRECT USER ID AND PASSWORD.....\n");


    }
    fclose(log2);
}
int studentlogin()
{
    int ch;
    printf("MENU: \n");
    printf("1.REGISTER A NEW ACCOUNT \n");
    printf("2.LOGIN \n");

    printf(" PLEASE ENTER YOUR CHOICE: ");
    scanf("%d",&ch);

    {
        switch(ch)
        {
        case 0:
            exit(0);
        case 1:
            registe2();
            break;
        case 2:
            login2();
            break;
        default :
            printf("INVALID CHOICE.....\N");
            break;
        }

    }

    return 0;
}
