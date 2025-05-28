#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
    }
    vector<int> l(n+1,INT_MAX);
    for(int i=0; i<n; i++)l[x[i]]=i;
    vector<int> b;
    set<pair<int,int>> ma,mi;
    set<int> ls;
    for(int i=0; i<=n; i++){
        ls.insert(l[i]);
    }
    for(int i=0; i<=*ls.begin(); i++){
        ma.insert(make_pair(-x[i],i));
        mi.insert(make_pair(x[i],i));
    }
    int i=0;
    vector<bool> re(n+1);
    while(mi.size()){
        auto& cur = (b.size()%2==0)?ma:mi;
        auto [val, id] = *cur.begin();
        cur.erase(cur.begin());
        b.push_back(val);
        re[abs(val)]=true;
        while(*ls.begin()!=INT_MAX&&re[x[*ls.begin()]]){
            int j = *ls.begin()+1;
            ls.erase(ls.begin());
            for(;j<=min(*ls.begin(),n-1); j++){
                mi.insert({x[j],j});
                ma.insert({-x[j],j});
            }
        }
        i=id+1;
        while(ma.size()&&(re[-ma.begin()->first]||ma.begin()->second<i))ma.erase(ma.begin());
        while(mi.size()&&(re[mi.begin()->first]||mi.begin()->second<i))mi.erase(mi.begin());
    }
    cout<<b.size()<<"\n";
    for(auto& i:b)cout<<abs(i)+1<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}