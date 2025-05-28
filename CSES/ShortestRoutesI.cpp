#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, m;
	cin>>n>>m;
	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		adj[--a].push_back({--b, c});
	}
	vector<int> dist(n, 7e18);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dist[0] = 0; 
	pq.push({0, 0});
	while (!pq.empty()) {
		const auto [d, i] = pq.top();
		pq.pop();
        if(d!=dist[i])continue;
        for(auto&[c,di]:adj[i]){
            if(di+d<dist[c]){
                dist[c] = di+d;
                pq.push({dist[c],c});
            }
        }
	}
	for (int i=0; i<n; i++)cout<<dist[i]<<" \n"[i==n-1];
}