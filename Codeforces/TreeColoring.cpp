#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> depth(n + 1, -1);
  vector<int> parent(n + 1, 0);
  vector<vector<int>> levels;
  queue<int> q;
  q.push(1);
  depth[1] = 0;
  parent[1] = -1;
  int maxWidth = 0;
  int maxChildren = 0;
  while (!q.empty()) {
    int levelSize = q.size();
    maxWidth = max(maxWidth, levelSize);
    levels.push_back({});
    for (int i = 0; i < levelSize; i++) {
      int u = q.front();
      q.pop();
      levels.back().push_back(u);
      int childCount = 0;
      for (int v : adj[u]) {
        if (depth[v] == -1) {
          depth[v] = depth[u] + 1;
          parent[v] = u;
          q.push(v);
          childCount++;
        }
      }
      maxChildren = max(maxChildren, childCount);
    }
  }
  int k = max(maxWidth, 1 + maxChildren);
  vector<int> color(n + 1, -1);
  for (auto &level : levels) {
    int nextColor = 0;
    for (int v : level) {
      int parentColor = (parent[v] == -1) ? -1 : color[parent[v]];
      if (nextColor == parentColor)
        nextColor = (nextColor + 1) % k;
      color[v] = nextColor;
      nextColor = (nextColor + 1) % k;
    }
  }
  vector<vector<int>> operations(k);
  for (int v = 1; v <= n; v++) {
    operations[color[v]].push_back(v);
  }
  cout << k << "\n";
  for (int i = 0; i < k; i++) {
    cout << operations[i].size();
    for (int v : operations[i]) {
      cout << " " << v;
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
