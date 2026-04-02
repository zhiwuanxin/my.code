#include<iostream>
using namespace std;
int X, Y, x, y;
long long arr[30][30];
int x1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int t1[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int main()
{
    cin >> X >> Y >> x >> y;
    cout << endl;
    for(int k = 0; k < 8; k++)
    {
        int xx = x + 2 + x1[k];
        int yy = y + 2 + t1[k];
        arr[xx][yy] = -1;    
    }
    arr[x + 2][y + 2] = -1;
    arr[2][2] = 1;
    for(int i = 2; i <= X + 2; i++)
    {
        
        for(int j = 2; j <= Y + 2; j++)
        {
            if(i == 2 && j == 2) continue;
            if(arr[i][j] == -1) continue;
            if(arr[i - 1][j] != -1) arr[i][j] += arr[i - 1][j];
            if(arr[i][j - 1] != -1)arr[i][j] += arr[i][j - 1];
        }
    }
    for(int i = 0; i <= X + 2; i++)
    {
        for(int j = 0; j <= Y + 2; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    cout << arr[X + 2][Y + 2];
    return 0;
}