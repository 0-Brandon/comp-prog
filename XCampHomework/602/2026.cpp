#include<bits/stdc++.h>
using namespace std;
const int N=2000005;

vector<vector<char>>mp;
vector<vector<int>>pos;
int n,m;
void left(){
	for(int i=1;i<=n;i++)
	for(int j=1,k=2;j<=m;j++){
		if(mp[i][j]=='.'){
			k=max(k,j+1);
			for(;k<=m;k++)if(mp[i][k]!='.'){
				swap(mp[i][j],mp[i][k]);
				break;
			}
		}
	}
}
void right(){
	for(int i=1;i<=n;i++)
	for(int j=m,k=m-1;j>=1;j--)
	if(mp[i][j]=='.'){
		k=min(k,j-1);
		for(;k>=1;k--)if(mp[i][k]!='.'){
			swap(mp[i][j],mp[i][k]);
			break;
		}
	}
}
void up(){
	for(int i=1;i<=m;i++)
	for(int j=1,k=2;j<=n;j++)
	if(mp[j][i]=='.'){
		k=max(k,j+1);
		for(;k<=n;k++)if(mp[k][i]!='.'){
			swap(mp[j][i],mp[k][i]);
			break;
		}
	}
}
void down(){
	for(int i=1;i<=m;i++)
	for(int j=n,k=n-1;j>=1;j--)
	if(mp[j][i]=='.'){
		k=min(k,j-1);
		for(;k>=1;k--)if(mp[k][i]!='.'){
			swap(mp[j][i],mp[k][i]);
			break;
		}
	}
}
void remove(char st){
	if(st=='U')up();
	if(st=='D')down();
	if(st=='L')left();
	if(st=='R')right();
}
void sleft(){
	for(int i=1;i<=n;i++)
	for(int j=1,k=2;j<=m;j++)
	if(!pos[i][j]){
		k=max(k,j+1);
		for(;k<=m;k++)if(pos[i][k]){
			swap(pos[i][j],pos[i][k]);
			break;
		}
	}
}
void sright(){
	for(int i=1;i<=n;i++)
	for(int j=m,k=m-1;j>=1;j--)
	if(!pos[i][j]){
		k=min(k,j-1);
		for(;k>=1;k--)if(pos[i][k]){
			swap(pos[i][j],pos[i][k]);
			break;
		}
	}
}
void sup(){
	for(int i=1;i<=m;i++)
	for(int j=1,k=2;j<=n;j++)
	if(!pos[j][i]){
		k=max(k,j+1);
		for(;k<=n;k++)if(pos[k][i]){
			swap(pos[j][i],pos[k][i]);
			break;
		}
	}
}
void sdown(){
	for(int i=1;i<=m;i++)
	for(int j=n,k=n-1;j>=1;j--)
	if(!pos[j][i]){
		k=min(k,j-1);
		for(;k>=1;k--)if(pos[k][i]){
			swap(pos[j][i],pos[k][i]);
			break;
		}
	}
}
vector<char>step;
void f(){
    vector lift(n+1,vector<pair<int,int>>(m+1));
    vector nxt(n+1,vector<pair<int,int>>(m+1));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(mp[i][j]=='.')pos[i][j]=0;
		else pos[i][j]=(i-1)*m+j;
		nxt[i][j]={0,0};
	}
	if(step.size()==0)return ;
	for(int i=0;i<4;i++){
		char ord=step[i];
		if(ord=='L')sleft();
		if(ord=='R')sright();
		if(ord=='U')sup();
		if(ord=='D')sdown(); 
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		if(pos[i][j]){
			int ii=pos[i][j]/m+1;
			if(pos[i][j]%m==0)ii--;
			int jj=pos[i][j]-(ii-1)*m;
			nxt[ii][jj]={i,j};
		}
	}
    vector tmp(n+1,vector<int>(m+1));
	int sum=step.size()/4;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(nxt[i][j].first==0)nxt[i][j]={i,j};
	while(sum){
		if(sum&1){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					tmp[nxt[i][j].first][nxt[i][j].second]=mp[i][j];
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					mp[i][j]=tmp[i][j];
		}
		sum>>=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				lift[i][j]=nxt[nxt[i][j].first][nxt[i][j].second];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				nxt[i][j]=lift[i][j];
	}
}
bool check(char a,char b){
	if((a=='L'||a=='R')&&(b=='L'||b=='R'))return 1;
	if((a=='U'||a=='D')&&(b=='U'||b=='D'))return 1;
    return 0;
} 
map<char,bool>used;
string s;
void work(){
    int cnt = 0;
	int q=s.size()-1;
    string rk(q,0);
	for(int i=q-1;i>=1;i--)if(check(s[i],s[i+1]))s[i]=s[i+1];
	for(int i=1;i<=q;i++){
		if(cnt>=2&&rk[cnt-1]==s[i])continue;
	   	while(check(rk[cnt],s[i]))cnt--;
	   	if(cnt>=2&&rk[cnt-1]==s[i])continue;
	   	rk[++cnt]=s[i];
	}
	for(int i=1;i<=cnt;i++)step.push_back(rk[i]);
	return;
}
void solve(){
	cin>>n>>m;
	step.clear();
	used.clear();
	mp.clear();
	pos.clear();
	mp.resize(n+5);
	pos.resize(n+5);
	for(int i=0;i<n+5;i++){
		mp[i].resize(m+5);
		pos[i].resize(m+5);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
    cin>>s;
    s = '0'+s;
	work();
	int nw=step.size();
	for(int i=0;i<min(nw,4);i++)remove(step[i]);
	for(int i=0;i<min(nw,4);i++)step.erase(step.begin());
	while(step.size()%4!=0){
		remove(step[0]);
		step.erase(step.begin());
	}
	f();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<mp[i][j];
		cout<<"\n";
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)solve();
}