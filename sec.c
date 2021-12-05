#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int aim = 0;
    int d = 0;
    int f = 0;
    int temp;
    int x;
    char n[100];
    while (1)
    {
        scanf("%s %d", n, &x); 
        if (strcmp(n,"forward") == 0)
        {
            f += x;
            temp = x*aim;
            d += temp;
        }
        else if (strcmp(n,"up") == 0)
        {
            aim-=x;
        }
        else if (strcmp(n, "down") == 0)
        {
            aim+=x;
        }
        else 
        {
            break;
        }
    }
    printf("%d\n", d * f);


}
