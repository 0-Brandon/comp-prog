#include <bits/stdc++.h>

using namespace std;
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) { 
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};
struct Edge{
    int x,y,weight;
    Edge(int a, int b, int w):x(a),y(b),weight(w){}
    bool operator < (const Edge& i) const{
        return weight<i.weight;
    }
};
int main(){
    freopen("moocast.out","w",stdout);
    freopen("moocast.in","r",stdin);
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    DSU dsu(n);
    vector<Edge> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int dist=(y[i]-y[j])*(y[i]-y[j]) + (x[i]-x[j])*(x[i]-x[j]);
            d.push_back(Edge(i,j,dist));
        }
    }
    sort(d.begin(),d.end());
    int ec=0;
    int ans = 0;
    for(auto i:d){
        if(!dsu.same(i.x,i.y)){
            dsu.unite(i.x,i.y);
            ec++;
        }
        if(ec==n-1){
            ans = i.weight;
            break;
        }
    }
    cout<<ans;
}