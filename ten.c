#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char arr[1000];
    int last;
} stack_t;

int process(char *buffer)
{
    stack_t stack;
    stack.last = -1;
    char exp;
    
    for(int i = 0; i < strlen(buffer); i++)
    {
        if (stack.last != -1)
        {
            if (stack.arr[stack.last] == '(')
            {
                exp = ')';
            }
            
            else if (stack.arr[stack.last] == '[')
            {
                exp = ']';
            }
            else if (stack.arr[stack.last] == '{')
            {
                exp = '}';
            }
            else if (stack.arr[stack.last] == '<')
            {
                exp = '>';
            }
        }
        else 
            exp = '*';

        if(buffer[i] == '(')
        {
            stack.last++;
            stack.arr[stack.last] = '(';
        }

        else if(buffer[i] == '[')
        {
            stack.last++;
            stack.arr[stack.last] = '[';
        }

        else if(buffer[i] == '{')
        {
            stack.last++;
            stack.arr[stack.last] = '{';
        }

        else if(buffer[i] == '<')
        {
            stack.last++;
            stack.arr[stack.last] = '<';
        }

        else if(buffer[i] == ')')
        {
            if (exp != buffer[i])
            {
                return 3;
            }
            stack.last--;
        }
            
        else if(buffer[i] == ']')
        {
            if (exp != buffer[i])
            {
                return 57;
            }
            stack.last--;
        }

        else if(buffer[i] == '}')
        {
            if (exp != buffer[i])
            {
               return 1197;
            }
            stack.last--;
        }

        else if(buffer[i] == '>')
            {
            if (exp != buffer[i])
            {
               return 25137;
            }
            stack.last--;
        }
    }
    return 0;
}

long long fill(char* buffer)
{
    stack_t stack;
    stack.last = -1;
    char exp;
    
    for(int i = 0; i < strlen(buffer); i++)
    {
        if (stack.last != -1)
        {
            if (stack.arr[stack.last] == '(')
            {
                exp = ')';
            }
            
            else if (stack.arr[stack.last] == '[')
            {
                exp = ']';
            }
            else if (stack.arr[stack.last] == '{')
            {
                exp = '}';
            }
            else if (stack.arr[stack.last] == '<')
            {
                exp = '>';
            }
        }
        else 
            exp = '*';

        if(buffer[i] == '(')
        {
            stack.last++;
            stack.arr[stack.last] = '(';
        }

        else if(buffer[i] == '[')
        {
            stack.last++;
            stack.arr[stack.last] = '[';
        }

        else if(buffer[i] == '{')
        {
            stack.last++;
            stack.arr[stack.last] = '{';
        }

        else if(buffer[i] == '<')
        {
            stack.last++;
            stack.arr[stack.last] = '<';
        }

        else if(buffer[i] == ')')
        {
            if (exp != buffer[i])
            {
                return 3;
            }
            stack.last--;
        }
            
        else if(buffer[i] == ']')
        {
            if (exp != buffer[i])
            {
                return 57;
            }
            stack.last--;
        }

        else if(buffer[i] == '}')
        {
            if (exp != buffer[i])
            {
               return 1197;
            }
            stack.last--;
        }

        else if(buffer[i] == '>')
        {
            if (exp != buffer[i])
            {
               return 25137;
            }
            stack.last--;
        }
    }

    long temp = 0;
    long left = stack.last + 1;

    for (int i = 0; i < left; i++)
    {
        if (stack.arr[stack.last] == '(')
        {
            temp = 5*temp + 1;
        }
        if (stack.arr[stack.last] == '[')
        {
            temp = 5*temp + 2;
        }
        if (stack.arr[stack.last] == '{')
        {
            temp = 5*temp + 3;
        }
        if (stack.arr[stack.last] == '<')
        {
            temp = 5*temp + 4;
        }
        stack.last--;
    }
    
    return temp; 
}



void swap(long long* xp, long long* yp)
{
    long long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// Function to perform Selection Sort
void selectionSort(long long arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver code

int main()
{
    FILE* fp;
    fp = fopen("test", "r");
    char buffer[1000];
    char **new = NULL;
    int num = 0;

    while (fgets(buffer, 1000, fp))
    {
        if (process(buffer) == 0)
        {
            new = realloc(new,(num+1)*sizeof(char*));
            new[num] = malloc(strlen(buffer)+1);
            strcpy(new[num], buffer);
            num++;
        }
    }

    long long *usp = malloc(num*sizeof(long long));
    long long temp;

    for (int i = 0; i < num; i++)
    {
        usp[i] = fill(new[i]);
        printf("%lld\n", usp[i]);
    }

    selectionSort(usp, num);

    printf("%lld\n", usp[num/2]);

    return 0;
}
