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
    int a,b,w;
    Edge(int x, int y, int we):a(x),b(y),w(we){}
    bool operator > (const Edge& i) const{
        return w>i.w;
    }
};
int n, m;
vector<Edge> elist;
vector<int> x(n);
bool test(int k){
    DSU dsu(n);
    for(auto i:elist){
        if(i.w<k) break;
        dsu.unite(i.a,i.b);
    }
    for(int i=0; i<n; i++){
        if(i!=x[i]&&!dsu.same(i,x[i])){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    x.resize(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
    }
    bool flag = false;
    for(int i=1; i<n; i++){
        if(x[i]<x[i-1]){
            flag=true;
        }
    }
    
    for(int i=0; i<m; i++){
        int a, b,c;
        cin>>a>>b>>c;
        elist.push_back(Edge(--a,--b,c));
    }
    if(flag){
    sort(elist.begin(),elist.end(),greater<Edge>());
    int low = 1, high = elist.begin()->w;
    int ans = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(test(mid)){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    cout<<ans;
    }
    else{
        cout<<"-1";
    }
}