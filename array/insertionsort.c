#include<stdio.h>
int main()
{
    int l;
    printf("\n Enter the lenght of the array.");
    scanf("%d",&l);
    int data[l];
    int i,j,b;
    // entering members in the array.
    printf("\n Enter the elements of the array \n");
    for(i=0;i<l;i++)
    {
        scanf(" %d",&data[i]);
    }
    printf("\n");
    printf("\n");
    // array before sorting.
    for(i=0;i<l;i++)
    {
        printf("%d  ",data[i]);
    }
    printf("\n");
    //sorting the array using insertion sort.
    for(i=1;i<l;i++)
    {
        b=data[i];
        j=i-1;
        while(j>=0&&b<data[j])
        {
            data[j+1]=data[j];
            j=j-1;
        }
        data[j+1]=b;
    }
    printf("The Array after sorting is:");
    printf("\n");
    for(i=0;i<l;i++)
    {
        printf("%d  ",data[i]);
    }
    printf("\n");
    return 0;
}