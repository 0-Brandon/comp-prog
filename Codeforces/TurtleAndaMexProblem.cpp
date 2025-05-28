#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    vector<vector<int>> mex(2,vector<int>(n));
    map<int,vector<int>> rev;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        int l;cin>>l;
        vector<int> cur(l);
        for(int j=0; j<l; j++){
            cin>>cur[j];
        }
        sort(cur.begin(),cur.end());
        cur.erase(unique(cur.begin(),cur.end()),cur.end());
        int b=0,j=0;
        for(; j<cur.size(); j++){
            while(cur[j]!=j+b){
                mex[b][i]=j+b;
                b++;
                if(b==2)break;
            }
            if(b==2)break;
        }
        if(b==0)mex[0][i]=j,mex[1][i]=j+1;
        if(b==1)mex[1][i]=j+1;
        rev[mex[0][i]].push_back(i);
        ans[i] = mex[1][i];
    }
    vector<vector<int>> adj(n);
    vector<int> ind(n);
    for(int i=0; i<n; i++){
        for(auto& j:rev[mex[1][i]]){
            adj[i].push_back(j);
            ind[j]++;
        }
    }
    vector<int> ord;
    queue<int> q;
    for(int i=0; i<n; i++)if(ind[i]==0)q.push(i);
    while(!q.empty()){
        int i=q.front();q.pop();
        ord.push_back(i);
        for(auto& c:adj[i])if(--ind[c]==0)q.push(c);
    }
    //propogate answer backwards through graph
    for(int i=n-1; i>=0; i--){
        for(auto& c:adj[ord[i]]){
            ans[ord[i]]=max(ans[ord[i]], ans[c]);
        }
    }
    int mans = 0;
    for(auto& i:rev){
        if(i.second.size()==1)continue;//comment this for easy version
        //there are two, we can take any chain from this mex
        for(auto& j:i.second){
            mans = max(mans,ans[j]);
        }
    }
    for(int i=0; i<n; i++){
        mans = max(mans,mex[0][i]);
    }
    int fans = (min(mans,m)+1)*mans;
    if(m>=mans) fans+= ((mans+1)+m)*(m-(mans+1)+1)/2;
    for(int i=0; i<n; i++){
        if(mex[0][i]<=min(mans,m)&&ans[i]>=mans){
            fans+=ans[i]-mans;
        }
        else if(mex[0][i]>=mans&&mex[0][i]<=m){
            fans+=ans[i]-mex[0][i];
        }
    }
    //if m < mans, everything default takes mans
    cout<<fans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}