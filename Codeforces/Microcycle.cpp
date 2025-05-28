#include <bits/stdc++.h>

using namespace std;
struct DSU
{
    vector<int> e;
    DSU(int n) : e(n, -1){};
    int par(int a) { return e[a] < 0 ? a : e[a] = par(e[a]); }
    int get(int a) { return -e[par(a)] - 1; }
    bool merge(int a, int b)
    {
        a = par(a), b = par(b);
        if (a == b)
            return false;
        if (e[a] > e[b])
            swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges;
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--,b--;
        edges.push_back({c, a, b});
    }
    sort(edges.rbegin(), edges.rend(),[&](auto i, auto j){return i[0]<j[0];});
    pair<int, int> me = {0, 0};
    int nans = 0;
    vector<vector<int>> adj(n);
    for (auto &i : edges)
    {
        if (dsu.merge(i[1], i[2]))
        {
            adj[i[1]].push_back(i[2]);
            adj[i[2]].push_back(i[1]);
        }
        else{
            
            nans = i[0];
            me = {i[1], i[2]};
        }
    }
    vector<int> ans;
    auto dfs = [&](auto dfs, int i, int p, int t) -> bool
    {
        if (i == t)
        {
            ans.push_back(i);
            return true;
        }
        for (auto &c : adj[i])
            if (c != p)
            {
                if (dfs(dfs, c, i, t))
                {
                    ans.push_back(i);
                    return true;
                }
            }
        return false;
    };
    dfs(dfs,me.first, -1, me.second);
    cout << nans << " "<<ans.size()<<"\n";
    for (auto &i : ans)
        cout << i+1 << " ";
    cout << "\n";
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}