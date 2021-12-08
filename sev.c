#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define abs(x) (x < 0)? -x : x
    

int *lineToArr(FILE* fp, int *size)
{
    int *arr = NULL;
    int x;

    while (fscanf(fp, "%d,", &x) != EOF)
    {
        arr = realloc(arr, (*size + 1) * sizeof(int));
        arr[*size] = x;
        (*size)++;
    }

    return arr;
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMin(int *arr, int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

int findMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

long long usedFuel(int* arr, int size, int pos)
{
    long fuel = 0;
    long temp;
    long abs;
    for (int i = 0; i < size; i++)
    {
        temp = 0;
        if (arr[i] - pos < 0)
            abs = -(arr[i] - pos);
        else 
            abs = arr[i] - pos;

        for (int i = 0; i < abs; i++)
        {
            temp += i + 1;
        }
        fuel += temp;
    }
    return fuel;
}

int main()
{
    FILE* fp;
    fp = fopen("test", "r");
    int size = 0;
    int *arr = lineToArr(fp, &size);
    int min = findMin(arr, size);
    int max = findMax(arr, size);
    long long minf = LONG_MAX;
    long long usedF;

    for (int i = min; i < max; i++)
    {
        usedF = usedFuel(arr, size, i);
        if(usedF < minf)
        {
            minf = usedF;
        }
    }

    printf("%lld\n", minf);

    return 0;
}
