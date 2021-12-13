#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foldBy(int** matrix, int *numRows, int numCols, int where);

void foldBx(int** matrix, int numRows, int* numCols, int where);

int main()
{
    FILE* fp;
    fp = fopen("test", "r");
    char buffer[100];
    int fold;
    int sum = 0;
    int numRows = 2000;
    int numCols = 2000;
    int **matrix = malloc(numRows*sizeof(int*));
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = malloc(numCols*sizeof(int));
    }
    for (int i = 0; i < 2000; i++)
    {
        for(int j = 0; j < 2000; j++)
        {
            matrix[i][j] = 0;
        }
    }
    int x ,y;
    int minCols = 0;
    int minRows = 0;
    char* token;
    while (fscanf(fp, "%d,%d", &x, &y) == 2)
    {
        if(x > minCols)
        {
            minCols = x;
        }
        if(y > minRows)
        {
            minRows = y;
        }
        matrix[y][x] = 1;
    }
    numRows = minRows + 2;
    numCols = minCols + 1;
    matrix = realloc(matrix, numRows * (sizeof(int*)));
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = realloc(matrix[i], numCols*sizeof(int));
    }

    sum = 0;
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if(matrix[i][j] == 1)
            {
                sum++;
            }
        }
    }
    printf("%d\n", sum);

    /*
    for (int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    */
    while (fgets(buffer, 100, fp))
    {
        token = strtok(buffer, "=");
        token = strtok(NULL, "=");
        fold = atoi(token);
        if(buffer[11] == 'y')
        {
            foldBy(matrix, &numRows, numCols, fold);
        }
        if(buffer[11] == 'x')
        {
            foldBx(matrix, numRows, &numCols, fold);
        }
    }
    sum = 0;
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if(matrix[i][j] == 1)
            {
                sum++;
            }
        }
    }
    printf("%d\n", sum);

    for (int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            if(matrix[i][j] == 1)
            {
                printf("#");
            }
            else 
                printf(" ");
        }
        printf("\n");
    }
    printf("numcols = %d, numrows = %d\n", numCols, numRows);
}

void foldBy(int** matrix, int *numRows, int numCols, int where)
{
    if((*numRows) - 1 == 2*where)
        puts("y");
    for (int i = 0; i < where; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (matrix[(*numRows)-1-i][j] == 1 && matrix[i][j] == 0)
            {
                matrix[i][j] = 1;
            }
        }
    }
    *numRows = where;
    return;
}
void foldBx(int** matrix, int numRows, int* numCols, int where)
{
    if (2*where == (*numCols) - 1)
    {
        puts("x");
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < where; j++)
            {
                if (matrix[i][*numCols-j-1] == 1 && matrix[i][j] == 0)
                {
                    matrix[i][j] = 1;
                }
            }
        }
        
        *numCols = where;
        return;
    }
}

