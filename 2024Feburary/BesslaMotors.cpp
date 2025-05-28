#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, M, C, R, K; 
int aans=0;
struct Edge {
    int to; 
    int weight; 
    Edge(int t, int w) : to(t), weight(w) {}
};
void bfs(int start, int R, vector<vector<Edge>>& adj, vector<bool>& visited, vector<int>& count) {
    queue<pair<int, int>> q; 
    q.push({start, 0}); 
    visited[start] = true; 
    while (!q.empty()) {
        int u = q.front().first; 
        int d = q.front().second; 
        q.pop(); 
        for (Edge e : adj[u]) {
            int v = e.to; 
            int w = e.weight; 
            if (!visited[v] && d + w <= R ) { 
                q.push({v, d + w}); 
                visited[v] = true; 
                if(v>C)count[v]++;
                if(count[v]==K&&v>C)aans++;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N >> M >> C >> R >> K; 
    vector<vector<Edge>> adj(N+1); 
    for (int i = 0; i < M; i++) {
        int u, v, l; 
        cin >> u >> v >> l;
        adj[u].push_back(Edge(v, l)); 
        adj[v].push_back(Edge(u, l)); 
    }
    vector<int> count(N + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= C; i++) { 
        vector<bool> visited(N + 1, false); 
        bfs(i, R, adj, visited, count); 
    }
    cout<<aans<<"\n";
    for (int i = C + 1; i <= N; i++) { 
        if (count[i] >= K) {
            cout<<i<<"\n";
        }
    }
}