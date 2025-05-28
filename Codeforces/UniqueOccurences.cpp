#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;cin>>n;
    vector<vector<pair<int,int>>> ed(n);
    for(int i=0; i<n-1; i++){
        int a, b, c;cin>>a>>b>>c;
        a--,b--,c--;
        ed[c].push_back({a,b});
    }
    vector<int> e(n);
    vector<int> sz(n,1);
    vector<pair<int&,int>> roll;
    iota(e.begin(),e.end(),0);
    auto par = [&](int i){
        while(i!=e[i])i = e[i];
        return i;
    };
    auto unite = [&](int i, int j){
        i=par(i); j=par(j);
        if(i==j)return;
        if(sz[i]<sz[j])swap(i,j);
        //i is the bigger one
        roll.push_back({sz[i],sz[i]});
        roll.push_back({e[j],j});
        sz[i]+=sz[j];
        e[j]=i;
    };
    auto rollback = [&](int s){
        while(roll.size()>s){
            roll.back().first=roll.back().second;
            roll.pop_back();
        }
    };
    long long ans = 0;
    auto split = [&](auto&& split, int i, int j)-> void {
       // cout<<i<<" ";
        if(i==j){
            for(auto& [a,b]:ed[i]){
                ans+=(long long)sz[par(a)]*sz[par(b)];
            }
            return;
        }
        int mid = (i+j)/2;
        int keep = roll.size();
        {
            for(int k=i; k<=mid; k++){
                for(auto& [a,b]:ed[k])unite(a,b);
            }
            split(split,mid+1,j);
            rollback(keep);
        }
        {
            for(int k=mid+1; k<=j; k++){
                for(auto& [a,b]:ed[k])unite(a,b);
            }
            split(split,i,mid);
            rollback(keep);
        }
    };
    split(split, 0,n-1);
    cout<<ans<<"\n";
}