#include<iostream>
#include<vector>
using namespace std;
const int N = 11;
vector<int> v[2],t[2];
int n, maxs;
int arr[N][N];
void dfs(int x, int y, int s)
{
    if(x == n && y == n)
    {
        t[0].push_back(x);
        t[1].push_back(y);
        s += arr[x][y];
        if(s > maxs) 
        {
            maxs = s;
            v[1].assign(t[1].begin(),t[1].end());
            v[0].assign(t[0].begin(),t[0].end());
        }
        t[0].pop_back();
        t[1].pop_back();
    }
    if(x > n || y > n) return;
    t[0].push_back(x);
    t[1].push_back(y);
    s += arr[x][y];
    dfs(x + 1, y, s);
    dfs(x, y + 1, s);
    t[0].pop_back();
    t[1].pop_back();
    s -= arr[x][y];
}
int main()
{
    cin >> n;
    int x, y, num, t;
    do{
        cin >> x >> y >> num;
        arr[x][y] = num;
    }while(x != 0 || y != 0 || num != 0);
    dfs(1, 1, 0);
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << arr[i][j] <<" ";
    //     }
    //     cout << endl;
    // }

    t = maxs;
    maxs = 0;
    for(size_t i = 0; i < v[0].size(); i++)
    {
        arr[v[0][i]][v[1][i]] = 0;
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << arr[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    dfs(1, 1, 0);
    cout << t + maxs;
    return 0;
}