#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
        x[i].first+=x[i].second;
        //must be completed before x[i].first
    }
    //sort by deadline
    sort(x.begin(),x.end(),[&](auto i, auto j){return i.first==j.first?i.second<j.second:i.first<j.first;});
    multiset<int> s;
    int t = 0;
    for(int i=0; i<n; i++){
        s.insert({x[i].second});
        t+=x[i].second;
        if(t>x[i].first){
            t-=*--s.end();
            s.erase(--s.end());
        }
    }
    cout<<s.size()<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}