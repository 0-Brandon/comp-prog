#include <bits/stdc++.h>//CLosing THe farm//No work because logic for solving problem is wrong

using namespace std;
struct DSU {
    vector < int > e;
    DSU(int n): e(n, -1) {}
    int par(int a) {
        return e[a] < 0 ? a : e[a] = par(e[a]);
    }
    bool merge(int a, int b) {
        a = par(a), b = par(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        return true;
    }
};
int main() {
    freopen("closing.out","w",stdout);
    freopen("closing.in","r",stdin);
    int n, m;
    cin >> n >> m;
    vector < pair < int, int >> edges;
    vector < vector < int >> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({--a,--b});
    }
    vector < int > x(n);
    vector < int > order(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        order[--x[i]] = i;
    }
    for (auto & [u, v]: edges) {
        //order[u] greater means u closes later// reopens first
        if (order[u] > order[v]) adj[v].push_back(u);
        else adj[u].push_back(v);
    }
    vector < string > ans(n);
    DSU dsu(n);
    int comps = 0;
    for (int i = n - 1; i >= 0; i--) {
        comps++;
        for (auto& child: adj[x[i]]) {
            if (dsu.merge(child, x[i])) {
                comps--;
            }
        }
        if (comps <= 1) {
            ans[i] = "YES";
        } else {
            ans[i] = "NO";
        }
    }
    for (int i=0; i<n; i++){
        cout << ans[i] << "\n";
    }
}