#include<iostream>
#include<cstring>
using namespace std;
const int N = 305;
int dp[N][N], sum[N][N];
int n;
int main()
{
    cin >> n;
    int temp;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        sum[1][i] += temp + sum[1][i - 1];
        dp[i][i] = 0;
        for(int j = 2; j <= n; j++)
            sum[j][i] = sum[1][i] - sum[1][j - 1];
    }
    for(int i = 2; i <= n; i++)
    {
        for(int l = 1; l + i - 1 <= n; l++)
        {
            int r = l + i - 1;
            for(int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[l][k] + sum[k + 1][r]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}