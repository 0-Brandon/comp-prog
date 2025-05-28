#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans;
vector<vector<int>> A(50,vector<int>(50));
vector<vector<map<int,int>>> M1(50,vector<map<int,int>>(50)), M2(50,vector<map<int,int>>(50));
void dfs1(int v,int x,int y){
	if(x>n||y>m)return;
	if(x+y-1==n)++M1[x][y][v];
	else{
		v^=A[x][y];
		dfs1(v,x+1,y);
		dfs1(v,x,y+1);
	}
}
void dfs2(int v,int x,int y){
	if(x<1||y<1)return;
	v^=A[x][y];
	if(x+y-1==n)++M2[x][y][v];
	else{
		dfs2(v,x-1,y);
		dfs2(v,x,y-1);
	}
}
signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>A[i][j];
	dfs1(0,1,1);
	dfs2(0,n,m);
	for(int i=1;i<=n;++i)
		for(auto &it:M1[i][n-i+1]){
			int kk=it.first;
			ans+=it.second*M2[i][n-i+1][kk^k];
		}
	cout<<ans;
	return 0;
}