#include <bits/stdc++.h>


using namespace std;

void solve(){
    int n;cin>>n;
    int l = -1;
    int fid = -1;
    vector<int> x(n);
    int lid = -1;
    vector<array<int,3>> queries;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(x[i]!=-1&&fid==-1)fid = i;
        if(x[i]!=-1)lid = i;
        if(x[i]!=-1){
            if(l!=-1)queries.push_back({l,i,i-l+1});
            l=i;
        }
    }
    if(fid==-1){for(int i=0; i<n; i++)cout<<((i&1)?1:2)<<" ";cout<<"\n";return;}
    for(int i=fid-1; i>=0; i--){
        x[i] = ((fid-i)&1)?x[fid]*2:x[fid];
    }
    auto lca = [&](int i, int j){
        vector<int> l, r;
        while(__lg(i)<__lg(j)){
            r.push_back(j);
            j>>=1;
        }
        while(__lg(i)>__lg(j)){
            l.push_back(i);
            i>>=1;
        }
        while(i!=j){
            l.push_back(i);
            r.push_back(j);
            i/=2,j/=2;
        }
        l.push_back(i);
        reverse(r.begin(),r.end());
        for(auto& k:r)l.push_back(k);
        return l;
    };
    for(auto&[i,j,k]:queries){
        vector<int> l = lca(x[i],x[j]);
        if(l.size()>k||((l.size()&1)!=(k&1))){
            cout<<"-1\n";return;
        }
        for(int o=0; o<l.size(); o++){
            x[o+i]=l[o];
        }
        for(int o = i+l.size(), b=1; o<j; o++){
            if(b)x[o] = x[o-1]*2;
            else x[o] = x[o-1]/2;
            b^=1;
        }
    }
    for(int i=lid+1; i<n; i++){
        x[i] = ((i-lid)&1)?x[lid]*2:x[lid];
    }
    for(auto& i:x)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}