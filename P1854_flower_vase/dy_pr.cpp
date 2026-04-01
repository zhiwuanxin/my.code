#include<iostream>
using namespace std;
int arr[105][105][2];
int f, v;
void dfs(int n, int pos)
{
    if(n == 0) return;
    dfs(n - 1, arr[n][pos][1]);
    cout << pos << " ";

}
int main()
{
    cin >> f >> v;
    int maxx, t = 1;
    for(int i = 1; i <= f; i++)
    {
        for(int j = 1; j <= v; j++) cin >> arr[i][j][0];
    }
    for(int i = 2; i <= f; i++)
    {
        maxx = -1e9;
        int maxpos;
        for(int j = i - 1; j <= v - f + i - 1; j++)
        {
            if(arr[i - 1][j][0] > maxx) 
            {
                maxx = arr[i - 1][j][0];
                maxpos = j;
            }
            arr[i][j + 1][0] += maxx;
            arr[i][j + 1][1] = maxpos;
        }
        t++;
    }
    maxx = -1e9;
    int y;
    for(int i = f; i <= v; i++)
    {
        if(arr[f][i][0] > maxx) 
        {
            maxx = arr[f][i][0];
            y = i;
        }
    }
    
    // for(int i = 1; i <= f; i++)
    // {
    //     for(int j = 1; j <= v; j++)
    //     {
    //         cout << arr[i][j][0] << "," << arr[i][j][1] << " ";
    //     }
    //     cout <<endl;
    // }
    cout << maxx<< endl;
    dfs(f, y);

    return 0;
}