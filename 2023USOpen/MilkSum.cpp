#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin>>n;
    ll t=0;
    vector<pair<int,int>> input(n+1);
    vector<int> x(n+1);
    vector<int> index(n+1);
    for(int i=1; i<=n; i++){
        cin>>input[i].first;
        input[i].second=i;
    }
    sort(input.begin(),input.end());
    for(int i=1; i<=n; i++){
        x[i]=input[i].first;
        index[input[i].second]=i;
    }
    vector<ll> pref(n+1,0);
    for(int i=1; i<=n; i++){
        pref[i]=1LL*pref[i-1]+x[i];
        t+=1LL*i*x[i];
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int idx, b;
        ll ans = t;
        cin>>idx>>b;
        idx=index[idx];
        ans-=1LL*idx*x[idx];
        if(b<x[idx]){
            int jdx = max((int)(lower_bound(x.begin(),x.end(),b)-x.begin()),1);
        	ans+=1LL*(jdx)*b;
            ans+=1LL*pref[idx-1]-pref[jdx-1];
        }else{
            int jdx = (upper_bound(x.begin(),x.end(),b)-x.begin());
        	ans+=1LL*(jdx-1)*b;
            ans-=1LL*pref[jdx-1]-pref[idx];
        }
        cout<<ans<<"\n";
    }
}
/*
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        vector<int> temp(x);
        int a, b;
        cin>>a>>b;
        temp[--a]=b;
        ll ans=0;
        sort(temp.begin(),temp.end());
        for(int i=0; i<n; i++){
            ans+=1LL*(i+1)*temp[i];
        }
        cout<<ans<<"\n";
    }
}
*/