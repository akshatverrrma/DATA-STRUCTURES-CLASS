#include<stdio.h>
#include<math.h>
int main()
{
    int l,beg,end,item,mid,lb,ub;
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
    beg=0;
    end=l-1;
    mid=floor((beg+end)/2);
    printf("Enter the value you want to search.%d\n",mid);
    scanf("%d",&item);
    while(beg<=end && item!=data[mid])
    {
       
        if(item<data[mid])
        {
            end=mid-1;
        }
        else
        {
            beg=mid+1;
        }
        mid=floor((beg+end)/2);
    }
     if(item==data[mid])
        {
            printf("\n the value you entered is at the position('%d')",mid);
        }
    printf("\n");
    return 0;
}

