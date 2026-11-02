#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> val(n + 1);
    int total = 0;
    int root;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        int v;
        cin >> v;
        val[i] = v;
        total += v;
        adj[p].push_back({i, i});
        if (p != 0)
            adj[i].push_back({p, i});
        else
            root = i;
    }

    int ans1 = -1;
    if (total % 3)
    {
        cout << -1 << endl;
        return;
    }
    int s = total / 3;
    int ans2 = -1;
    auto dfs = [&](auto &&dfs, int u, int p) -> int
    {
        int sum = val[u];

        for (auto it : adj[u])
        {
            if (it.first != p)
            {
                sum += dfs(dfs, it.first, u);
            }
        }
        if (sum == s && u != root)
        {
            // cerr << u << " " << sum << endl;
            if (ans1 == -1)
            {
                ans1 = u;
            }
            else if (ans2 == -1)
                ans2 = u;
            return 0;
        }
        return sum;
    };
    dfs(dfs, root, 0);
    if (ans2 == -1)
        cout << -1 << endl;
    else
        cout << ans1 << " " << ans2 << endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}