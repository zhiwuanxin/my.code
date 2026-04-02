#include<iostream>

using namespace std;
int arr[13][13], dp[13][13][13][13];
int n;
int mymax(int i, int j, int k, int l)
{
    return max(max(i, j), max(k, l));
}
int main()
{
    cin >> n;
    int x, y, s;
    while(cin >> x >> y >> s && x) arr[x][y] = s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    if(i + j == k + l){
                        int t = mymax(dp[i][j - 1][k][l - 1], dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1], dp[i - 1][j][k - 1][l]);
                        dp[i][j][k][l] += t + arr[i][j] + arr[k][l];
                    }
                    if(i == k && j == l) dp[i][j][k][l] -= arr[i][j];
                }
            }
        }
    }
    cout << dp[n][n][n][n];

    return 0;
}