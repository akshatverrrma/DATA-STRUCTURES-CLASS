#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    char address[50];
    int marks;
};
int main()
{
    int n;
    printf("Enter the no of entries: ");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++)
    {
        printf("enter your name\n");
        scanf("%s\n",&s[i].name);
        printf("enter your roll no.\n");
        scanf("%d\n",&s[i].roll);
        printf("enter your address\n");
        scanf("%s\n",&s[i].address);
        printf("enter your marks\n");
        scanf("%d\n",&s[i].marks);
    }
    for(int i=0;i<n;i++)
    {
        printf("------------------------\n");
        printf("name is %s\n",s[i].name);
        printf("roll no is %d\n",s[i].roll);
        printf("address is %s\n",s[i].address);
        printf("marks are %d\n",s[i].marks);
    }
    return 0;
}