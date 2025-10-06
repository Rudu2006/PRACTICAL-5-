#include <stdio.h>
#include <string.h>

void LRS(char S[])
{
    int n = strlen(S);
    int C[n+1][n+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            C[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(S[i-1] == S[j-1] && i != j)
            {
                C[i][j] = C[i-1][j-1] + 1;
            }
            else
            {
                C[i][j] = (C[i-1][j] > C[i][j-1]) ? C[i-1][j] : C[i][j-1];
            }
        }
    }

    int lrslen = C[n][n];
    printf("LRS length: %d\n", lrslen);

    char lrs[n+1];
    int index = lrslen;
    lrs[index] = '\0';

    int i = n, j = n;
    while(i > 0 && j > 0)
    {
        if(S[i-1] == S[j-1] && i != j)
        {
            lrs[index-1] = S[i-1];
            i--;
            j--;
            index--;
        }
        else if(C[i-1][j] > C[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Longest Repeating Sequence: %s\n\n", lrs);
}

int main()
{
    char X[] = "AABCBDC";
    char Y[] = "AABEBCDD";

    LRS(X);
    LRS(Y);

    return 0;
}
