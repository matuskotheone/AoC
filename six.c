#include <stdio.h>
#include <stdlib.h>

const int NUM_DAYS = 256;

void spawnFish(int** arr, int index, long long  *size)
{
    *arr = realloc(*arr, (*size + 1) * sizeof(int));
    (*arr)[*size] = 9;
    (*arr)[index] = 6;
    (*size)++;
    return;
}

long long* day(long long *arr)
{
    long long *temp = malloc(9*sizeof(long long));
    temp[0] = arr[1];
    temp[1] = arr[2];
    temp[2] = arr[3];
    temp[3] = arr[4];
    temp[4] = arr[5];
    temp[5] = arr[6];
    temp[6] = arr[7] + arr[0];
    temp[7] = arr[8];
    temp[8] = arr[0];
    free(arr);
    return temp;
}

int main()
{
    FILE* fp;
    long long *arr = malloc(9*sizeof(long long));
    fp = fopen("test", "r");
    int x;
    long long sum = 0;
    while (fscanf(fp, "%d," , &x) != EOF)
    {
        arr[x]++;
    }

/*
    for (int i = 0; i < 9; i++)
    {
        printf("%lld \n", arr[i]);
    }
*/

    for (int i = 0; i < NUM_DAYS; i++)
    {
        arr = day(arr);
    }

    for (int i = 0; i < 9; i++)
    {
        sum += arr[i];
    }


    printf("%lld \n", sum);

    free(arr);
    return 0;
}
