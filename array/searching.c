#include<stdio.h>
int main()
{
    int a[20];
    int i,s,count=0;
    // entering members in the array.
    printf("\nEnter the elements of the array \n");
    for(i=0;i<10;i++)
    {
        scanf("\t %d",&a[i]);
    }
    printf("\n");
    printf("\n ENTER THE ELEMENT YOU WANT TO SEARCH.");
    scanf("\n %d",&s);
    // searching for the no.
     for(i=0;i<10;i++)
    {
        if(a[i]==s)
        {
            count++;
            // to count how many times the no. is present.
            printf("\n The no. you have entered is present at location %d",i+1);
        }
    }
    printf("\n");
    if(count==1)
    {
        printf("\n THE NO. %d YOU HAVE ENTERED FOR SEARCHING IS PRESENT IN THE ARRAY.",s);
        printf("\n IT IS REPEATED ONLY ONCE.");
    }
    else if(count>1)
    {
        printf("\n THE NO. %d YOU HAVE ENTERED FOR SEARCHING IS PRESENT IN THE ARRAY.",s);
        printf("\n IT HAS REPEATED IN THE ARRAY %d TIMES",count);
    }
    else
    {
        printf("THE NO. YOU HAVE ENTERED IS NOT PRESENT IN THE ARRAY");
    }
    printf("\n");
}
