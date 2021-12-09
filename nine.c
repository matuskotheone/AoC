#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLow(int **arr, int i, int j, int numRows, int numItems)
{
    if (arr[i][j] == 9)
        return 0;
    if (i != 0 && arr[i-1][j] < arr[i][j])
    {
        //printf("teraz som tu %d\n", __LINE__);
        return 0;
    }

    if (i != numRows-1 && arr[i+1][j] < arr[i][j])
    {
        //printf("teraz som tu %d\n", __LINE__);
        return 0;
    }

    if (j != 0 && arr[i][j-1] < arr[i][j])
    {
        //printf("teraz som tu %d\n", __LINE__);
        return 0;
    }

    if (j != numItems - 1 && arr[i][j+1] < arr[i][j])
    {
        //printf("teraz som tu %d\n", __LINE__);
        return 0;
    }

    return 1;
}

int mapping(int** arr, int i, int j, int** visited, int numRows, int numItems)
{
    if (i < 0 || j < 0 || i == numRows || j == numItems || visited[i][j] || arr[i][j] == 9)
    {
        return 0;
    }

    visited[i][j] = 1;
    
    return 1 + mapping(arr, i + 1, j, visited, numRows, numItems) 
        + mapping(arr, i - 1, j, visited, numRows, numItems) 
        + mapping(arr, i, j + 1, visited, numRows, numItems) 
        + mapping(arr, i, j - 1, visited, numRows, numItems); 
}

int main()
{
    FILE* fp;
    fp = fopen("test", "r");
    char buffer[1000];
    int numRows = 0;
    int x;
    int sum = 1;
    int max3[3] = {0};
    char idk[2];
    int numItems;
    int **arr = NULL;

    while(fgets(buffer, 1000, fp))
    {
        arr = realloc(arr, (numRows + 1) * sizeof(int*));
        arr[numRows] = NULL;
        numItems = 0;
        for (int i = 0; buffer[i+1] != '\0'; i++)
        {
            arr[numRows] = realloc(arr[numRows], (i+1) * sizeof(arr));
            idk[0] = buffer[i];
            idk[1] = '\0';
            arr[numRows][i] = atoi(idk);
            numItems++;
        }
        numRows++;
    }

    int **visited = malloc(numRows * sizeof(int*));

    for (int i = 0; i < numRows; i++)
    {
        visited[i] = malloc(numItems*sizeof(int));
        for (int j = 0; j < numItems; j++)
        {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numItems; j++)
        {
            if (isLow(arr, i, j, numRows, numItems) && !visited[i][j])
            {
                x = mapping(arr, i, j, visited, numRows, numItems);
                if (x > max3[0])
                {
                    max3[2] = max3[1];
                    max3[1] = max3[0];
                    max3[0] = x;
                }
                else if (x > max3[1])
                {
                    max3[2] = max3[1];
                    max3[1] = x;
                }
                else if (x > max3[2])
                {
                    max3[2] = x;
                }
            }
        }
    }

    /*
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numItems; j++)
        {
            printf("%d ", arr[i][j]); 
        }
        printf("\n");
    }
    */
    for (int i = 0; i < 3; i++)
    {
        sum *= max3[i];
    }
    printf("%d\n", sum);


    return 0;
}
