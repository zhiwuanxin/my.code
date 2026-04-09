#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5;
int n, arr[N], dp[N], len;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= n; i++)
    {
        if(len == 0 || arr[i] > dp[len]) dp[++len] = arr[i];
        else
        {
            int l = 1, r = len;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if(dp[mid] > arr[i]) r = mid;
                else l = mid + 1;
            }
            dp[l] = arr[i];
        }
    }
    cout << len;
    return 0;
}