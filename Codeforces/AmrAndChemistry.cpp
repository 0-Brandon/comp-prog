#include <bits/stdc++.h>
#define int long long
using namespace std;
int sz=1<<17;
vector<int> res(sz+2,0), ile(sz+2,0);
int ans = INT_MAX;
void dfs(int i, int r, int s){
    ans=min(ans,r+res[i]);
    if(i>=sz/2)return;
    int cur = ile[i]-ile[i*2]-ile[i*2+1];
    dfs(i*2,res[i*2+1]+2*ile[i*2+1]+r+s+cur,s+ile[2*i+1]+cur);
    if(s+cur+ile[i*2]==0){
        dfs(i*2+1,0,0);
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        ile[a]++;
    }
    for(int i=sz/2; i>=1; i--){
        res[i]+=res[i*2]+res[i*2+1]+ile[i*2]+ile[2*i+1];
        ile[i]+=ile[i*2+1]+ile[i*2];
    }
    dfs(1,0,0);
    cout<<ans<<"\n";
}