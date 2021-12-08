#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CISLO 1000


int main()
{
    FILE* fp;
    fp = fopen("txt", "r");
    int x1, x2, y1, y2;
    int j;
    int sum = 0;
    int matrix[CISLO][CISLO] = {0};
    int y = 0;
    while (1)
    {
        if (fscanf(fp, "%d,%d -> %d,%d\n", &x1, &x2, &y1, &y2) == EOF)
        {
            break;
        }


        //printf("kokot\n");
        if (x1 == y1)
        {
            if(x2 < y2)
            {
                printf("%d\n", __LINE__);
                for(int i = x2; i <= y2; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[x1][i]++;
                }
            }
            else 
            {
                printf("%d\n", __LINE__);
                for(int i = y2; i <= x2; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[x1][i]++;
                }

            }
        }
        else if (x2 == y2)
        {
            if(x1 < y1)
            {
                printf("%d\n", __LINE__);
                for(int i = x1; i <= y1; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[i][x2]++;
                }
           }
            else 
            {
                printf("%d\n", __LINE__);
                for(int i = y1; i <= x1; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[i][x2]++;
                }
            }
        }
        else if (x1 - y1 == x2 - y2)
        {
            int g = 0;
            if(x1 < y1)
            {
                printf("%d\n", __LINE__);
                for(int i = x1; i <= y1; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[x1+g][x2+g]++;
                    g++;
                }
           }
            else 
            {
                printf("%d\n", __LINE__);
                for(int i = y1; i <= x1; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[y1+g][y2+g]++;
                    g++;
                }
            }
        }

        else if (x1 - y1 == -(x2- y2))
        {
            j = 0;
            if(x1 < y1)
            {
                printf("%d\n", __LINE__);
                for(int i = x1; i <= y1; i++)
                {
                    //printf("%d\n", ++y);
                    matrix[x1+j][x2-j]++;
                    j++;
                }
           }
            else 
            {
                printf("%d\n", __LINE__);
                for(int i = y1; i <= x1; i++)
                {
                    matrix[x1-j][x2+j]++;
                    j++;
                }
            }
        }
    }


    for (int i = 0; i < CISLO; i++)
    {
        for (int j = 0; j < CISLO; j++)
        {
            if (matrix[i][j] == 0)
            {
                printf(".");
                continue;
            }
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < CISLO; i++)
    {
        for (int j = 0; j < CISLO; j++)
        {
            if(matrix[i][j]>1)
            {
                sum++;
            }
        }
    }

    printf("%d\n" , sum);

    fclose(fp);
    return 0;
}
