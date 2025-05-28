#include <bits/stdc++.h>

#define int long long
using namespace std;

constexpr int inf = 1e17;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
signed main(){
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int p, q;
  cin >> p >> q;
  vector<vector<char>> c(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c[i][j];
    }
  }
  vector<vector<int>> id(n, vector<int>(m));
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i][j] != '#'){
        id[i][j] = cnt;
        cnt++;
      }
    }
  }
  vector<vector<pair<int, int>>> E(cnt);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      int t = -1;
      if (c[i][j] == 'U'){
        t = 0;
      }
      if (c[i][j] == 'L'){
        t = 1;
      }
      if (c[i][j] == 'D'){
        t = 2;
      }
      if (c[i][j] == 'R'){
        t = 3;
      }
      if (t != -1){
        for (int k = 0; k < 4; k++){
          if (k != t){
            int x = i + dx[k];
            int y = j + dy[k];
            if (0 <= x && x < n && 0 <= y && y < m){
              if (c[x][y] != '#'){
                int u = id[x][y];
                int v = id[i + dx[t]][j + dy[t]];
                if (k != (t ^ 2)){
                  E[u].push_back(make_pair(p, v));
                } else {
                  E[u].push_back(make_pair(q, v));
                }
              }
            }
          }
        }
      }
    }
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> d(cnt, inf);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i][j] == '.'){
        pq.push(make_pair(0, id[i][j]));
      }
    }
  }
  while (!pq.empty()){
    int t = pq.top().first;
    int v = pq.top().second;
    pq.pop();
    if (d[v] == inf){
      d[v] = t;
      for (pair<int, int> P : E[v]){
        int w = P.second;
        if (d[w] == inf){
          pq.push(make_pair(t + P.first, w));
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (c[i][j] != '#'){
        if (i < n - 1){
          if (c[i + 1][j] != '#'){
            ans = min(ans, d[id[i][j]] + d[id[i + 1][j]]);
          }
        }
        if (j < m - 1){
          if (c[i][j + 1] != '#'){
            ans = min(ans, d[id[i][j]] + d[id[i][j + 1]]);
          }
        }
      }
    }
  }
  if (ans == inf){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}