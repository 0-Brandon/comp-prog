#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[305][305];
bitset<305>b[305];

bool gauss(){
	for(int i=0;i<n;i++)for(int j=0;j<=n;j++)b[i][j]=a[i][j];
	int r=0;
	for(int i=0;i<n;i++){
		int j=r;
		while(j<n&&!b[j][i])j++;
		if(j==n)continue;
		swap(b[r],b[j]);
		for(int j=r+1;j<n;j++)if(b[j][i])
			b[j]^=b[r];
		r++;
	}
	for(int j=r;j<n;j++)if(b[j][n])return false;
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)for(int j=0;j<=n;j++)
			a[i][j]=0;
		for(int i=0;i<m;i++){
			int u,v,w;
            cin>>u>>v>>w;
			a[u][n]^=w;a[v][n]^=w;
			a[u][u]^=1;a[v][v]^=1;
			a[u][v]^=1;a[v][u]^=1;
		}
		cout<<(gauss()?"yes":"no")<<"\n";
	}
}