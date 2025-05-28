#include <bits/stdc++.h>

using namespace std;

pair<int,int> add(pair<int,int> x, char s){
    if(s=='U')return {x.first, x.second+1};
    if(s=='D')return {x.first, x.second-1};
    if(s=='L')return {x.first-1,x.second};
    return {x.first+1,x.second};
}
int main(){
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    map<pair<int,int>,vector<int>> pos;
    vector<pair<int,int>> p(n+1);
    pair<int,int> cur = {0,0};
    for(int i=0; i<=n; i++){
        pos[cur].push_back(i);
        p[i]=cur;
        if(i<n)cur = add(cur,s[i]);
    }
    auto check = [&] (pair<int,int> i,int  l, int r){
        auto it = lower_bound(pos[i].begin(),pos[i].end(),l);
        if(it!=pos[i].end()&&*it<=r)return true;
        return false;
    };
    for(int i=0; i<q; i++){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        l--,r--;
        pair<int,int> ne = make_pair(p[l].first+p[r+1].first-x,p[l].second+p[r+1].second-y);
        if(check({x,y},0,l)||check({x,y},r+1,n)||check(ne,l+1,r)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}