#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MATRIX_SIZE 5

typedef struct Collumn {
    int num;
    bool marked;
}
col_t;

typedef struct Board {
    col_t col[5][5];
}
board_t;

board_t* board_ctor()
{
    board_t* new = malloc(sizeof(board_t));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            new->col[i][j].marked = false;
        }
    }
    return new;
}

board_t** fillBoards(FILE* fp, int* num_boards)
{
    int x;
    int n = 0;
    board_t* curr_board = NULL;
    board_t** arr = NULL;
    int i = -1;
    int j = -1;
    while(1)
    {
        fscanf(fp, "%d", &x);

        if (x == -1)
        {
            break;
        }

        j = (j+1)%5;
        
        if (j == 0)
        {
            i = (i+1)%5;
        }

        if (j == 0 && i == 0)
        {
            n++;
            arr = realloc(arr, n * sizeof(board_t*));
            curr_board = board_ctor();
            arr[n-1] = curr_board;
        }
        curr_board->col[i][j].num = x;
    }
    *num_boards = n;
    return arr;

}

void printBoard(board_t* board)
{
    for (int i = 0; i < 5;i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board->col[i][j].num);
        }
        printf("\n");
    }
}

bool win(board_t* board, int row, int col)
{
    //printf("\n");
    bool found = false;
    for(int i = 0; i < 5; i++)
    {
        if (board->col[i][col].marked != true)
        {
            //printf("%d ", board->col[col][i].num);
            found = true;
            break;
        }
    }

    if (!found)
    {
        return 1;
    }

    found = false;
    for(int i = 0; i < 5; i++)
    {
        if (board->col[row][i].marked != true)
        {
            //printf("%d ", board->col[col][i].num);
            found = true;
            break;
        }
    }

    if (!found)
    {
        return 1;
    }

    return 0;

}

int winValue(board_t* board, int x)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!board->col[i][j].marked)
            {
                sum += board->col[i][j].num;    
            }
        }
    }
    return sum * x;
}


int run (board_t** arr, int num_boards, int *nums, int num_nums)
{
    for (int i = 0; i < num_nums; i++)
    {
        for (int j = 0; j < num_boards; j++)
        {   
            for(int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if (nums[i] == arr[j]->col[k][l].num)
                    {
                        arr[j]->col[k][l].marked = true;
                        if (win(arr[j], k, l))
                        {
                            //printf("%d\n", j);
                            return winValue(arr[j], nums[i]);
                        }
                    }
                }
            }
        }
        
    }

    return 0;
}

int main()
{
    FILE* fp;
    fp = fopen("frt", "r");
    char buffer[1000];
    int nums[1000];
    int num_nums = 0;
    char num[2];
    int num_boards;
    board_t** arr;
    fgets(buffer, 1000, fp);

    for(int i = 0; i < strlen(buffer); i++)
    {
        if (buffer[i] == '\n')
        {
            nums[num_nums] = atoi(num);
            num[0] = '\0';
            num[1] = '\0';
            num_nums++;
            break;
        }
        else if (buffer[i] == ',')
        {
            nums[num_nums] = atoi(num);
            num[0] = '\0';
            num[1] = '\0';
            num_nums++;
            continue;
        }
        else 
        {
            if (num[0] == '\0')
            {
                num[0] = buffer[i];
            }
            else 
            {
                num[1] = buffer[i];
            }
        }

    }


    arr = fillBoards(fp, &num_boards);

    printf("%d\n", run(arr, num_boards, nums, num_nums));








/*
    for (int i = 0; i < num_nums; i++)
    {
        printf("%d ", nums[i]); 
    }
    puts(" ");
*/
        

    return 0;
}
