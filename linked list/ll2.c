#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
int print_lis(struct node *n)
{
    while(n!=NULL)
    {
        printf("Element is %d;\t",n->data);
        n=n->next;
    }
    return 0;
}
int searching(struct node *head,int g)
{
    struct node* n=head;
    int pos=0;
    while(n!=NULL)
    {
        if (n->data==g)
        {
            return pos;
        }
        n=n->next;
        pos++;
    }
    return -1;
}
int main()
{
    struct node *head ,*prev, *p;
    head=(struct node *) malloc(sizeof(struct node));
    head=NULL;
    int n;
    printf("Enter The number of elements");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        p=(struct node *) malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next =NULL;
        if (head=NULL)
	    {
            head=p;
        }
        else
	    {
            prev->next=p;
            prev=p;
        }
    }
    printf("LINKED LIST \n");
    print_lis(head);
    int g;
    printf("ENTER THE ELEMENT YOU WANT TO SEARCH: \n");
    scanf("%d \n",&g);
    int pos= searching(head,g);
    if (pos==-1)
    {
        printf("The element is not present");
    }
    else
    {
        printf("The element is present at %d",pos+1); 
    }
    return 0;
}
