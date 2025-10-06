#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void LCS(string A, string B)
{
    int m = A.length();
    int n = B.length();
    
    int C[m+1][n+1];    
    
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            C[i][j] = 0;
        }
    }
    
     for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(A[i-1] == B[j-1])
            {
                C[i][j] = C[i-1][j-1] + 1;
            }
            else{
                C[i][j] = max(C[i-1][j], C[i][j-1] );
            }
        }
    }
    
    cout<<"Cost Matrix : "<<endl;
    
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            cout<<setw(2)<<C[i][j]<<" ";
            
        }
        cout<<endl;
    }
    
    cout<<endl;
    
    int lcslen = C[m][n];
    cout<<"LCS length : "<<lcslen<<endl;
    
    string lcs = "";
    int i = m, j = n;
    
    while(i>0 && j>0)
    {
        if(A[i-1]== B[j-1])
        {
            lcs = A[i-1] + lcs;
            i--;
            j--;
        }
        else{
            if(C[i-1][j] > C[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    
    cout<<"Longest Common Sequence : "<<lcs<<endl;
    
}

int main()
{
    
    string X = "AGCCCTAAGGGCTACCTAGCTT";
    string Y = "GACAGCCTACAAGCGTTAGCTTG";


    LCS(X, Y);
    
    return 0;
}

