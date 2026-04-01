#include<iostream>
using namespace std;
int f, v;
int arr[105][105], dp[105][105][2];
int dfs(int c, int r)
{
    if(c == f) return arr[c][r];
    int max = -1e9;
    if(dp[c][r][0]) return dp[c][r][0];
    int t;
    for(int i = r + 1; i <= c + 1 + v - f; i++)
    {
        if(dfs(c + 1, i) > max)
        {
            t = i;
            max = dfs(c + 1, i );
        }
    }
    dp[c][r][1] = t;
    dp[c][r][0] = max + arr[c][r];
    return dp[c][r][0];
}
void ddd(int i,int j)
{
    if(i == f) return;    
    cout << j << " ";
    ddd(i + 1, dp[i + 1][j][1]);

}
int main()
{

    cin >> f >> v;
    for(int i = 1; i <= f; i++)
    {
        for(int j = 1; j <= v; j++) cin >> arr[i][j];
    }
    cout << dfs(0, 0) << endl;
    // for(int i = 0; i <= f; i++)
    // {
    //     for(int j = 0; j <= v; j++)
    //     {
    //         cout << dp[i][j][0] << "," << dp[i][j][1] <<" ";
    //     }
    //     cout << endl;
    // }
    ddd(0, dp[0][0][1]);

    return 0;
}