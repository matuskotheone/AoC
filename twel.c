#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pair {
    char* first;
    char* second;
} pair_t;

typedef struct Forbidden {
    char* str;
} forb_t;

int paths(pair_t* rel, int n, char* curr, forb_t* forbidden, int forbNum, int twice, int first)
{
    int sum = 0;
    forb_t* newForb = malloc(forbNum*sizeof(forb_t));
    for(int i = 0; i < forbNum; i++)
    {
        newForb[i].str = malloc(strlen(forbidden[i].str)+1);
        strcpy(newForb[i].str, forbidden[i].str);
    }

    if (strcmp(curr,"start") == 0 && first != 1)
    {
        return 0;
    }

    if (curr[0] <= 'z' && curr[0] >= 'a' )
    {
        for (int i = 0; i < forbNum; i++)
        {
            if (strcmp(curr, newForb[i].str) == 0)
            {
                if (twice != 0)
                    return 0;
                else 
                {
                    twice = 1;
                    break;
                }
            }
        }
        newForb = realloc(newForb, (forbNum+1) * sizeof(forb_t));
        newForb[forbNum].str = malloc(strlen(curr)+1);
        strcpy(newForb[forbNum].str, curr); 
        forbNum++;
    }
    
    if (strcmp(curr, "end") == 0)
    {
        return 1;
    }

    
    
    for (int i = 0; i < n; i++)
    {
        if (strcmp(curr, rel[i].first) == 0)
        {
            sum += paths(rel, n, rel[i].second, newForb, forbNum, twice, 0);
        }
    }
    
    for(int i = 0; i < forbNum; i++)
    {
        free(newForb[i].str);
    }
    free(newForb);


    return sum;

}

int main()
{
    FILE* fp;
    fp = fopen("test", "r");
    char buffer[1000];
    char* token;
    pair_t* rel = NULL;
    int n = 0;
    while (fgets(buffer, 1000, fp))
    {
        rel = realloc(rel, (n + 2) * sizeof(pair_t)); 
        token = strtok(buffer, "-");
        rel[n].first = malloc(1+strlen(token));
        strcpy(rel[n].first, token);
        token = strtok(NULL, "-");
        token[strlen(token + 1)] = '\0';
        rel[n].second = malloc(strlen(token)+1);
        strcpy(rel[n].second, token);
        rel[n+1].first = malloc(strlen(rel[n].second)+1);
        strcpy(rel[n+1].first,rel[n].second);
        rel[n+1].second = malloc(strlen(rel[n].first)+1);
        strcpy(rel[n+1].second,rel[n].first);
        n += 2;
    }
    forb_t* forbidden = NULL;
    printf("%d\n", paths(rel, n, "start", forbidden, 0, 0, 1));

    return 0;

    /*
    for(int i = 0; i < n; i++)
    {
        printf("%s, %s \n", rel[i].first, rel[i].second);
    }
    */
}

