#include<iostream>
using namespace std;
const int N = 1e5 + 10, mo = 1e5 + 3;
int n, k;
int p[N];
int main()
{
    cin >> n >> k;
    p[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k && i - j >= 0; j++)
        {
            p[i] = (p[i - j] + p[i]) % mo;
        }
    }
    cout << p[n];
    return 0;
}