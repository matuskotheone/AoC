#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Hovno {
    int s;
    int n;
}
hovno_t;

int main()
{
    int x;
    int prev = INT_MAX;
    int inc = 0;

    hovno_t a,b,c;
    a.n = 0;
    a.s = 0;
    b.n = -1;
    b.s = 0;
    c.n = -2;
    c.s = 0;
    while(1)
    {
        scanf("%d", &x);
        if (x == 0)
            break;

        if(prev == INT_MAX)
        {
            prev = x;
            continue;
        }

        if (b.n < 0)
        {
            b.n++;
        }
        else if(b.n == 2)
        {
            b.s += x;
            if (b.s > prev)
            {
                inc++;
            }
            prev = b.s;
            b.n = 0;
            b.s = 0;
        }
        else
        {
            b.n++;
            b.s += x;
        }


        if (a.n < 0)
        {
            a.n++;
        }
        else if(a.n == 2)
        {
            a.s += x;
            if (a.s > prev)
            {
                inc++;
            }

            prev = a.s;
            a.n = 0;
            a.s = 0;
        }
        else
        {
            a.n++;
            a.s += x;
        }


        if (c.n < 0)
        {
            c.n++;
        }
        else if(c.n == 2)
        {
            c.s += x;
            if (c.s > prev)
            {
                inc++;
            }
            prev = c.s;
            c.n = 0;
            c.s = 0;
        }
        else
        {
            c.n++;
            c.s += x;
        }
    }
    printf("%d\n", inc);
}
