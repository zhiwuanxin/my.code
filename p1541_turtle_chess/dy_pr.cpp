#include<iostream>
using namespace std;
int arr[355], b[5];
int n, m;
int dp[41][41][41][41];
int main()
{
    cin >> n >> m;
    int x;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= m; i++) cin >> x, b[x]++;
    dp[0][0][0][0] = arr[1];
    for(int i = 0; i <= b[1]; i++)
            for(int j = 0; j <= b[2]; j++)
                for(int k = 0; k <= b[3]; k++)
                    for(int l = 0; l <= b[4]; l++)
                    {
                        int z = arr[1 + i + 2 * j + 3 * k + 4 * l];
                        if(j > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + z);
                        if(i > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + z);
                        if(k > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + z);
                        if(l > 0) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + z);
                    }
    cout << dp[b[1]][b[2]][b[3]][b[4]];


    return 0;
}