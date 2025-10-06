#include <stdio.h>
#include <string.h>

void LCS(char A[], char B[])
{
    int m = strlen(A);
    int n = strlen(B);
    int C[m+1][n+1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            C[i][j] = 0;
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(A[i-1] == B[j-1])
            {
                C[i][j] = C[i-1][j-1] + 1;
            }
            else
            {
                C[i][j] = (C[i-1][j] > C[i][j-1]) ? C[i-1][j] : C[i][j-1];
            }
        }
    }

    int lcslen = C[m][n];
    printf("LCS length: %d\n", lcslen);

    char lcs[lcslen + 1];
    int index = lcslen;
    lcs[index] = '\0';

    int i = m, j = n;
    while(i > 0 && j > 0)
    {
        if(A[i-1] == B[j-1])
        {
            lcs[index-1] = A[i-1];
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

    printf("Longest Common Sequence: %s\n", lcs);
}

int main()
{
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";

    LCS(X, Y);

    return 0;
}
