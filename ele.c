#include <stdio.h>
#include <stdlib.h>

const int ITERATION = 100;

void fetak(int arr[10][10])
{
        for (int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                arr[j][k] = 0;
            }
        }
}

int flash(int matrix[10][10], int flashed[10][10], int first)
{
    int sum = 0;
    int found;
    if (first)
    {
        for(int i = 0; i < 10; i++)
        {
            for (int j = 0 ; j < 10; j++)
            {
                matrix[i][j] = (matrix[i][j] + 1) % 10;
            }
        }
    }

jump:
    found = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matrix[i][j] == 0 && flashed[i][j] == 0)
            {   
                flashed[i][j] = 1;
                if (i - 1 >= 0 && j - 1 >= 0 && flashed[i-1][j-1] == 0 && matrix[i-1][j-1] != 0)
                    matrix[i-1][j-1] = (matrix[i-1][j-1] + 1) % 10;

                if (j - 1 >= 0 && flashed[i][j-1] == 0  && matrix[i][j-1] != 0)
                    matrix[i][j-1] = (matrix[i][j-1] + 1) % 10;

                if (i - 1 >= 0 && flashed[i-1][j] == 0 && matrix[i-1][j] != 0)
                    matrix[i-1][j] = (matrix[i-1][j] + 1) % 10;

                if (i + 1 < 10 && j - 1 >= 0 && flashed[i+1][j-1] == 0 && matrix[i+1][j-1] != 0)
                    matrix[i+1][j-1] = (matrix[i+1][j-1] + 1) % 10;

                if (i - 1 >= 0 && j + 1 < 10 && flashed[i-1][j+1] == 0 && matrix[i-1][j+1] != 0)
                    matrix[i-1][j+1] = (matrix[i-1][j+1] + 1) % 10;

                if (i + 1 < 10 && j + 1 < 10 && flashed[i+1][j+1] == 0 && matrix[i+1][j+1] != 0)
                    matrix[i+1][j+1] = (matrix[i+1][j+1] + 1) % 10;

                if (j + 1 < 10 && flashed[i][j+1] == 0 && matrix[i][j+1] != 0)
                    matrix[i][j+1] = (matrix[i][j+1] + 1) % 10;

                if (i + 1 < 10 && flashed[i+1][j] == 0 && matrix[i+1][j] != 0)
                    matrix[i+1][j] = (matrix[i+1][j] + 1) % 10;
                sum++;
                found = 1;
                break;
            }
            if (found)
                break;
        }
        if (found)
        {
            goto jump;
        }
    }
    return sum;
}

int main()
{
    FILE* fp;
    fp = fopen("test", "r");
    char buffer[11];
    int matrix[10][10];
    int flashed[10][10];
    int issame;
    int temp;
    int j = 0;
    int sum = 0;
    for (int j = 0; j < 10; j++)
    {
        fscanf(fp, "%s", buffer);
        for(int i = 0; i < 10; i++)
        {
            matrix[j][i] = buffer[i] - '0';
        }
    }

    for (int i = 0; 1; i++)
    {
        fetak(flashed);
        sum += flash(matrix, flashed, 1);
        temp = matrix[0][0];
        issame = 1;
        for (int k = 0; k < 10; k++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (matrix[k][j] != temp)
                {
                    issame = 0;
                }
            }
        }
        if(issame)
        {
            printf("%d\n\n", i+1);
            break;
        }
    }
    printf("%d\n", sum);

    /*
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    */
    return 0;
}
