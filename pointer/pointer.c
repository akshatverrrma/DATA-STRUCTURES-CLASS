#include <stdio.h>
int main()
{
    int x[5]={1,2,3,4,5};
    int*p=&x[5];
    for(int i=0;i<5;i++)
    {
        printf("the value stored in array is %u\n",*p+i+1);
        printf("the address of the values are %u\n",p);
    }
    return 0;
}