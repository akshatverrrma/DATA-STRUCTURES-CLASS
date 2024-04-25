#include<stdio.h>
struct student_record
{
    char name[12];
    int stuid;
    int roll;
    int batch;
};
int main()
{
    int n=2;
    struct student_record s[n];
    for(int i=1;i<=n;i++)
    {
        printf("Enter the name of student %d: ",i);
        scanf("%s",s[i].name);
        printf("\n");
        printf("Enter sap id of the student %d: ",i);
        scanf("%d", &s[i].stuid);
        printf("\n");
        printf("Enter the roll no. of student %d: ",i);
        scanf("%s",&s[i].roll);
        printf("\n");
        printf("Enter the batch of student %d: ",i);
        scanf("%d",&s[i].batch);
        printf("\n");
    }
}