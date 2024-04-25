#include<stdio.h>
int main()
{
    int a[20];
    int i,j,l;
    // entering members in the array.
    printf("\nEnter the elements of the array \n");
    for(i=0;i<10;i++)
    {
        scanf("\t %d",&a[i]);
    }
    printf("\n");
    //printing out the array.
    printf("\n The members of the array are:");
     for(i=0;i<10;i++)
    {
        printf("\t %d",a[i]);
    }
    printf("\n");
    // adding new value at the jth position.
    printf("\n Enter the position you want to add a new no. at \n");
    scanf("\n %d",&j);
    l= j-1;
    //creating space for new member in the array.
     for(i=9;i>=l;i--)
    {
        a[i+1]= a[i];
    }
    printf("\n");
    scanf(" \n %d", &a[l]);
    // printing the new array.
     for(i=0;i<11;i++)
    {
        printf("\t %d",a[i]);
    }
    printf("\n");
    // removing the 5th position.
     for(i=l;i<10;i++)
    {
        a[i]= a[i+1];
    }
    printf("\n");
    //printing again after removing the 5th position.
    printf("\n The array after removing the position at the jth place is now:");
     for(i=0;i<=10;i++)
    {
        printf("\t %d",a[i]);
    }
    printf("\n");
}