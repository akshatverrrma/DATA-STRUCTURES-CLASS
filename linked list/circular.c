#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;
void print(struct node * head){
    struct node * p= head;
    printf("%d\t", p->data);
    do{
        p=p->next;
        printf("%d\t", p->data);
    }while(p!= head);
}
int main(){
    node *head, *p;
    int n;
    printf("Enter the number of element:");
    scanf("%d", &n);
    head=(node*)malloc(sizeof(node));
    scanf("%d", &head->data);
    head->next=NULL;
    p=head;
    for(int i=1; i<n;i++){
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        p->next=head;
        scanf("%d", &p->data);
    }
    print(head);
}