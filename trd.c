#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define CISLO 12 

typedef struct Penis {
    int row[CISLO];
} penis_t;



int main()
{
    long x;
    int sum;
    long n = 0;
    long eps[CISLO];
    long gam[CISLO];
    long long gamd = 0;
    long long epsd = 0;
    penis_t *arr = NULL;

    while(1)
    {
        scanf("%ld", &x);
        if (x == 2)
            break;

        arr = realloc(arr, (n+1)*sizeof(arr->row));
        for(int i = CISLO-1; i >= 0; i--)
        {
            arr[n].row[i] = x % 10;
            x /= 10;
        }
        n++;
    }

    printf("peenis\n");



    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < CISLO; j++)
        {
            printf("%d ", arr[i].row[j]);
        }
        printf("\n");
    }

    bool fail;
    int invalid;

    for (int i = 0; i < CISLO; i++)
    {
        sum = 0;
        invalid = 0;
        for (int j = 0; j < n; j++)
        {
            fail = 0;
            if (i > 0)
            {
                for (int k = 0; k < i; k++)
                {
                    if (gam[k] != arr[j].row[k])
                    {
                        fail = 1;
                    }
                }
            }
            if (fail)
            {
                invalid++;
                continue;
            }
            sum += arr[j].row[i];
        }
        printf("%d invalid: %ld\n", sum, n-invalid);
        if (n - invalid == 1)
        {
            gam[i] = sum;
            continue;
        }
        if (sum*2 >= (n - invalid))
        {
            gam[i] = 1;
        }
        else
        {
            gam[i] = 0;
        }
    }

    for (int i = 0; i < CISLO; i++)
    {
        sum = 0;
        invalid = 0;
        for (int j = 0; j < n; j++)
        {
            fail = 0;
            if (i > 0)
            {
                for (int k = 0; k < i; k++)
                {
                    if (eps[k] != arr[j].row[k])
                    {
                        fail = 1;
                    }
                }
            }
            if (fail)
            {
                invalid++;
                continue;
            }
            sum += arr[j].row[i];
        }
        printf("%d invalid: %ld\n", sum, n-invalid);
        if (n - invalid == 1)
        {
            eps[i] = sum;
            continue;
        }
        if (sum*2 < (n - invalid))
        {
            eps[i] = 1;
        }
        else
        {
            eps[i] = 0;
        }
    }

    printf("kokot\n");

    for (int i = 0; i < CISLO; i++)
    {
        printf("%ld ", gam[i]);
    }
    printf("\n");

    for (int i = 0; i < CISLO; i++)
    {
        printf("%ld ", eps[i]);
    }
    printf("\n");


    for (int i = 0; i < CISLO; i++)
    {
        gamd += gam[i]*pow(2, CISLO-1-i);
        epsd += eps[i]*pow(2, CISLO-1-i);
    }

    printf("%lld", gamd * epsd);

    free(arr);


/*
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < CISLO; j++)
        {
            printf("%d ", arr[i].row[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < CISLO; i++)
    {
        printf("%lld\n", sum[i]);
    }
    
    for (int i = 0 ; i < CISLO; i++)
    {
        if (n/2 > sum[i])
        {
            gam[i] = 0;
            eps[i] = 1;
        }
        else 
        {
            gam[i] = 1;
            eps[i] = 0;
        }
    }

    for (int i = 0; i < CISLO; i++)
    {
        gamd += gam[i]*pow(2, CISLO-1-i);
        epsd += eps[i]*pow(2, CISLO-1-i);
    }

    printf("%lld", gamd * epsd);
*/
}
