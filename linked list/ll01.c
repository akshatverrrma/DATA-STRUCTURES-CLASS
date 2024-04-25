#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *n)
{
    while(n!=NULL)
    {
        printf("%d \t",n->data);
        n=n->next;
    }
}
int main()
{
    int n;
    printf("Enter how many nodes you want: \n");
    scanf("%d",&n);
    struct node *ptr[n];
    for(int i=0;i<n;i++)
    {
        ptr[i]=(struct node*)malloc(sizeof(struct node));
        if(ptr[i] == NULL)
        {
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("Enter the value for node %d\n",i+1);
        scanf("%d",&ptr[i]->data);
        if(i!=n-1)
            ptr[i]->next=ptr[i+1];
        else
            ptr[i]->next=NULL;
    }

    display(ptr[0]);
    return 0;
}