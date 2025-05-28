#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int qlr(vector<int>& x,int l,int r) {
	return x[r+1]-x[l];
}
void solve(){
	int n, q, m;
	cin>>n>>q>>m;
	vector<int> x(n);
	for(int i=0;i<n;i++) cin>>x[i];
	vector<int> ql(q),qr(q);
	vector<int> ans(q,0),g(q,0),f(q,0);
    vector<int> c(n+1),d(n+1);
	for(int i=0; i<q; i++){
		cin>>ql[i]>>qr[i];
		ql[i]--,qr[i]--;
		g[i] = qr[i]-ql[i]+1;
	}
	for(int k=1; k*k<=m; k++){
		for(int i=0; i<n; i++){
			if(x[i]==k)c[i+1] = c[i]+1;
			else c[i+1] = c[i];
			if((k+1)*x[i]>m&&k*x[i]<=m) d[i+1] = d[i]+1;
			else d[i+1] = d[i];
		}
		for(int i=0; i<q; i++){
			int l = ql[i], r = qr[i];
			int cx = qlr(c,l,r), dx = qlr(d,l,r);
			if(cx + f[i] >=dx){
				f[i] = cx+f[i]-dx;
				g[i]-=dx*2;
			}
			else{
				int r = (dx-cx-f[i]);
				if(g[i]-(cx+f[i])*2==1)continue;
				ans[i] += (r+1)/2;
				int z = cx+dx+f[i];
				if(g[i]<=z&&(r%2==1)){
					ans[i]--;
					continue;
				}
				f[i] = r&1;
				g[i] -= z-f[i];
			}
		}
	}
	for(auto& i:ans)cout<<i<<" ";
	cout<<"\n";
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)solve();
}