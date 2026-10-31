#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(4, -1));
    auto f = [&](auto &&f, int i, int j) -> int
    {
        if (i >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j == 0)
        {
            dp[i][j] = min(f(f, i + 1, j + 1), f(f, i + 1, j + 2));
        }
        if (j == 1)
            dp[i][j] = f(f, i + 1, j + 1);
        if (j == 2)
        {
            dp[i][j] = (a[i] == 1 ? 1 : 0) + min(f(f, i + 1, j + 1), f(f, i + 1, 0));
        }
        if (j == 3)
            dp[i][j] = (a[i] == 1 ? 1 : 0) + f(f, i + 1, 0);
        return dp[i][j];
    };
    cout << f(f, 0, 2) << endl;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}