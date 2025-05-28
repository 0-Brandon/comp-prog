#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> e; 
    DSU(int n):e(n,-1){}
	int par(int x) { return e[x] < 0 ? x : e[x] = par(e[x]); } 
	bool same(int a, int b) { return par(a) == par(b); }
	bool merge(int x, int y) {
		x = par(x), y = par(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};

int main(){
    int n, m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    for(int i=0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;
        a--,b--;
        edges.push_back({c,a,b});
    }
    sort(edges.rbegin(),edges.rend());
    int q;
    cin>>q;
    vector<pair<int,int>> queries;
    vector<int> l(q),r(q);
    for(int i=0; i<q; i++){
        int a, b;cin>>a>>b;a--,b--;
        queries.push_back({a,b});
        l[i]=0, r[i]=m;
    }
    for(int _=0; _<=100; _++){ 
        vector<vector<int>> ck(m+1);
        DSU dsu(n);
        for(int i=0; i<q; i++)if(l[i]<r[i]){
            int mi = l[i]+(r[i]-l[i])/2;
            ck[mi].push_back(i);
        }
        for(int i=0; i<m; i++){
            dsu.merge(edges[i][1],edges[i][2]);
            for(auto& j:ck[i]){
                if(dsu.same(queries[j].first,queries[j].second))r[j] = i;
                else l[j] =i+1;
            }
        }
    }
    for(int i=0; i<q-1; i++)cout<<(l[i]==m?-1:edges[l[i]][0])<<"\n";
    cout<<(l.back()==m?-1:edges[l.back()][0]);
}