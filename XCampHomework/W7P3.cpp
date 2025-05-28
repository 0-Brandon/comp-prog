#include <bits/stdc++.h>
 
using namespace std;
 
constexpr int maxn = 2e3 + 14;
 
int n, m, ev[maxn], eu[maxn], ew[maxn], l[maxn], r[maxn], col[maxn];
bool smax(int &a, int b){
    if(a < b)
        return a = b, true;
    return false;
}
bool smin(int &a, int b){
    if(a > b)
        return a = b, true;
    return false;
}
void solve(int st, bool fix_all = false){
    fill(col, col + n, -1);
    fill(l, l + n, -maxn);
    fill(r, r + n, maxn);
    l[st] = r[st] = col[st] = 0;
    while(true){
        bool changed = false;
        for(int e = 0; e < m; e++){
            int v = ev[e], u = eu[e];
            if(col[v] != -1){
                if(col[v] == col[u])
                    cout << "NO\n", exit(0);
                col[u] = !col[v];
            }
            else if(col[u] != -1)
                col[v] = !col[u];
            changed |= smax(l[v], l[u] - 1);
            changed |= smin(r[v], r[u] + (ew[e] ? -1 : 1));
            changed |= smax(l[u], l[v] + (ew[e] ? 1 : -1));
            changed |= smin(r[u], r[v] + 1);
        }
        for(int i = 0; i < n; i++)
            if(l[i] > r[i])
                cout << "NO\n", exit(0);
        if(!changed){
            int who = -1;
            for(int i = 0; i < n; i++)
                if(l[i] < r[i] && (who == -1 || r[i] > r[who]))
                    who = i;
            if(!fix_all || who == -1)
                break;
            l[who] = r[who];
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> ev[i] >> eu[i] >> ew[i], ev[i]--, eu[i]--;
    int mx = -1, best;
    for(int i = 0; i < n; i++){
        solve(i);
        int cur = *max_element(r, r + n);
        if(cur > mx)
            mx = cur, best = i;
    }
    cout << "YES\n" << mx << '\n';
    solve(best, true);
    for(int i = 0; i < n; i++)
        cout << r[i] << ' ';
    cout << '\n';
}