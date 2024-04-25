#include<stdio.h>
#include<math.h>
int main()
{
    int l,ending,item;
    printf("\n Enter the lenght of the array.");
    scanf("%d",&l);
    int data[l];
    int i,j,temp;
    // entering members in the array.
    printf("\n Enter the elements of the array \n");
    for(i=0;i<l;i++)
    {
        scanf("\t%d",&data[i]);
    }
    printf("\n");
    // printing members in the array.
    printf("\n Printing the elements of the array before sorting\n");
    for(i=0;i<l;i++)
    {
        printf("\t%d",data[i]);
    }
    printf("\n");
    // sorting using bubble sort algorithm
    for(j=1;j<=l-1;j++)
    {
        for(i=0;i<l;i++)
        {
            if(data[i+1]< data[i])
            {
                temp=data[i+1];
                data[i+1]=data[i];
                data[i]=temp;
            }
        }
    }
    // printing members in the array.
    printf("\n Printing the elements of the array after sorting\n");
    for(i=0;i<l;i++)
    {
        printf("\t%d",data[i]);
    }
    printf("\n");
}