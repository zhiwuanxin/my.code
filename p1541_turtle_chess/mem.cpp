#include<iostream>
using namespace std;
int arr[355], barrel[5];
int n, m;
int dp[41][41][41][41];
int dfs(int pos)
{
    int s = 0;
    if(pos == n) return arr[n];
    if(dp[barrel[1]][barrel[2]][barrel[3]][barrel[4]]) return dp[barrel[1]][barrel[2]][barrel[3]][barrel[4]];
    for(int i = 1; i <= 4; i++)
    {
        if(barrel[i] == 0) continue;
        barrel[i]--;
        s = max(s,dfs(pos + i));
        barrel[i]++;
    }
    dp[barrel[1]][barrel[2]][barrel[3]][barrel[4]] = s + arr[pos];
    return dp[barrel[1]][barrel[2]][barrel[3]][barrel[4]];
}

int main()
{
    int x; 
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= m; i++)
    {
        cin >> x;
        barrel[x]++;
    }
    cout << dfs(1);
    return 0;
}


