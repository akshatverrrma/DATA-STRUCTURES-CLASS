#include <stdio.h>
void insert_and_delete(int a[], int n, int i, int j, int value)
{
    if (i < 0 || i > n || j < 0 || j >= n)
    {
        printf("Invalid positions.\n");
        return;
    }
    for (int k = n - 1; k >= i; k--)
    {
        a[k+1] = a[k];
    }
    a[i] = value;
    for (int k = j; k < n - 1; k++)
    {
        a[k] = a[k+1];
    }
    printf("Modified array: ");
    for (int k = 0; k < n - 1; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
}
int main()
{
    int a1[] = {1, 2, 3, 4, 5};
    int n = sizeof(a1) / sizeof(a1[0]);
    int i = 2, j = 4, value = 6;
    insert_and_delete(a1, n, i, j, value);
    return 0;
}
