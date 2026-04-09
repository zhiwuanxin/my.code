#include<iostream>
using namespace std;
int tab[6][6] = {{0,0,0,0,0,0},{0,5,-1,-2,-1,-3},
{0,-1,5,-3,-2,-4},{0,-2,-3,5,-2,-2},
{0,-1,-2,-2,5,-1},{0,-3,-4,-2,-1,0}};
const int N = 105;
int dp[N][N], a[N], b[N];
int main()
{
    int na, nb;
    string aa, bb;
    cin >> na >> aa >> nb >> bb;
    for(int i = 1; i <= na; i++){
        if(aa[i - 1] == 'A') a[i] = 1;
        else if(aa[i - 1] == 'C') a[i] = 2;
        else if(aa[i - 1] == 'G') a[i] = 3;
        else if(aa[i - 1] == 'T') a[i] = 4;
    }
    for(int i = 1; i <= nb; i++){
        if(bb[i - 1] == 'A') b[i] = 1;
        else if(bb[i - 1] == 'C') b[i] = 2;
        else if(bb[i - 1] == 'G') b[i] = 3;
        else if(bb[i - 1] == 'T') b[i] = 4;
    }
    for(int i = 1; i <= na; i++) dp[0][i] = dp[0][i - 1] + tab[5][a[i]];
    for(int i = 1; i <= nb; i++) dp[i][0] = dp[i - 1][0] + tab[5][b[i]];
    for(int i = 1; i <= nb; i++)
    {
        for(int j = 1; j <= na; j++)
        {
            dp[i][j] = max(max(dp[i - 1][j] + tab[b[i]][5], dp[i - 1][j - 1] + tab[b[i]][a[j]]),
             dp[i][j - 1] + tab[a[j]][5]);
        }
    }    

    cout << dp[nb][na];
    return 0;
}