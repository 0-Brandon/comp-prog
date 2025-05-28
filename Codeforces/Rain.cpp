#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    m*=2;
    vector<int> x(n),p(n);
    map<int,int> t;
    for(int i=0; i<n; i++){
        cin>>x[i]>>p[i];
        x[i]*=2,p[i]*=2;
        t[x[i]-p[i]]+=1;
        t[x[i]]+=-2;
        t[x[i]+p[i]]+=1;
    }
    auto intersect = [&](pair<int,int> a, pair<int,int> b)->pair<int,int> {
        int tx = max(a.first+a.second,b.first+b.second);
        int ty = max(a.second-a.first,b.second-b.first);
        return {(tx-ty)/2,(tx+ty)/2};
    };
    int slope =0;
    int last = 0;
    int h = 0;
    pair<int,int> gr = {0,INT_MIN};
    for(auto& [cur,s]:t){
        if(last!=cur)h = h+(cur-last)*slope;
        if(h>m){
            gr = intersect(gr,{cur,h-m});
        }
        last=cur;
        slope+=s;
    }
    for(int i=0; i<n; i++){
        if(intersect(gr,{x[i],p[i]})==make_pair(x[i],p[i]))cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){solve();}
}