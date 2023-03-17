#include <stdio.h>


int main()
{
    printf("mennu");
    int d ;
    scanf("%d",&d);
    switch(d)
    {
    case 1:
        studmarks();
        break;
    case 2:


    }
}


void studmarks() {
	char name[50];
	int marks,i,n;
	printf("Enter number of students: ");
	scanf("%d",&n);
	FILE *fptr;
	fptr=(fopen("student.txt","w"));
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}
	for (i=0;i<n;++i) {
		printf("For student%d\nEnter name: ",i+1);
		scanf("%s",name);
		printf("Enter marks: ");
		scanf("%d",&marks);
		fprintf(fptr,"\nName: %s \nMarks=%d \n",name,marks);
	}
	fclose(fptr);

}
int  {
	char name[50];
	int marks,i,n;
	printf("Enter number of students: ");
	scanf("%d",&n);
	FILE *fptr;
	fptr=(fopen("student.txt","a"));
	if(fptr==NULL) {
		printf("Error!");
		exit(1);
	}
	for (i=0;i<n;++i) {
		printf("For student%d\nEnter name: ",i+1);
		scanf("%s",name);
		printf("Enter marks: ");
		scanf("%d",&marks);
		fprintf(fptr,"\nName: %s \nMarks=%d \n",name,marks);
	}
	fclose(fptr);
	return 0;
}


struct s {
	char name[50];
	int height;
};
int main() {
	struct s a[5],b[5];
	FILE *fptr;
	int i;
	fptr=fopen("file.txt","wb");
	for (i=0;i<5;++i) {
		fflush(stdin);
		printf("Enter name: ");
		gets(a[i].name);
		printf("Enter height: ");
		scanf("%d",&a[i].height);
	}
	fwrite(a,sizeof(a),1,fptr);
	fclose(fptr);
	fptr=fopen("file.txt","rb");
	fread(b,sizeof(b),1,fptr);
	for (i=0;i<5;++i) {
		printf("Name: %s\nHeight: %d",b[i].name,b[i].height);
	}
	fclose(fptr);
}
