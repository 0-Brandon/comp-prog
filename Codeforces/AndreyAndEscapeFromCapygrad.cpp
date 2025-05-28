#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> x;
    for(int i=0; i<n; i++){
        int l, r, a, b;
        cin>>l>>r>>a>>b;
        x.push_back({l,b});
    }
    sort(x.begin(),x.end());
    vector<pair<int,int>> m;
    m.push_back(x[0]);
    for(int i=1; i<n; i++){
        if(m.back().second>=x[i].first)m.back().second=max(m.back().second,x[i].second);
        else m.push_back(x[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        if(a<m[0].first){cout<<a<<" ";continue;}
        int idx = distance(m.begin(),upper_bound(m.begin(),m.end(),make_pair(a,(int)2e9)))-1;
        cout<<max(m[idx].second,a)<<" ";
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}