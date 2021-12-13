#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = malloc (10*sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    arr = realloc(arr, 8*sizeof(int));
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    
}
