
#include <bits/stdc++.h>
//Binary search on x, you can do topological sort for each test and it will run in time

using namespace std;
int n, m;
vector < int > ans;
vector < int > ind;
bool ok(int x, vector < vector < int>> & ob) {
    priority_queue < int > pq;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        ind[i] = 0;
    }
    for (int i = 0; i < x; i++) {
        for (int j=0; j<ob[i].size()-1; j++) {
            adj[ob[i][j]].push_back(ob[i][j+1]);
            ind[ob[i][j+1]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) pq.push(-i);
    }
    for (int i = 0; i < n; i++) {
        if (pq.empty()) return false;
        int cur = -pq.top();
        ans[i] = cur;
        pq.pop();
        for (auto & j: adj[cur]) {
            ind[j]--;
            if (ind[j] == 0) pq.push(-j);
        }
    }
    return true;
}
int main() {
    freopen("milkorder.out", "w", stdout);
     freopen("milkorder.in", "r", stdin);
    cin >> n >> m;
    ans.resize(n);
    ind.resize(n);
    vector < vector < int >> ob(m);
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int c;
            cin>>c;
            ob[i].push_back(c);
            ob[i][j]--;
        }
    }
    int low = 0, high = m +1;
    while (low < high) {
        int mid = low + (high - low+1) / 2;
        if (ok(mid, ob)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    ok(low, ob);
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1;
        if (i < n - 1) cout << " ";
    }
}
