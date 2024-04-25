#include <stdio.h>

int sum_array_recursive(int arr[], int i, int n) 
{
    if (i == n) 
    {
        return 0;
    }
    else 
    {
        return arr[i] + sum_array_recursive(arr, i+1, n);
    }
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = sum_array_recursive(arr, 0, n);
    printf("Sum of array elements: %d", sum);
    return 0;
}
