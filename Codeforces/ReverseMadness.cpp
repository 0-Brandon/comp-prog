#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    string s;
    cin>>n>>k;
    cin>>s;
    vector<pair<int,int>> idx(n);
    vector<int> l(k), r(k);
    for(int i=0; i<k; i++)cin>>l[i];
    for(int i=0; i<k; i++)cin>>r[i];
    for(int i=0; i<k; i++){
        l[i]--,r[i]--;
        for(int j=l[i]; j<=r[i]; j++){
            idx[j] = make_pair(l[i],r[i]);
        }
    }
    vector<bool> temp(n);
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int a;
        cin>>a;a--;
        a = min(a,idx[a].second + idx[a].first-a);
        temp[a]=!temp[a];
    }
    int c = 0;
    int rp = 0;
    for(int i=0; i<n; i++){
        if(i!=0&&idx[i].first!=idx[i-1].first){
            c=0;
        }
        if(temp[i]==1)c^=1;
        if(c==1&&(i-idx[i].first)<=(idx[i].second-idx[i].first)/2)swap(s[i],s[idx[i].second-(i-idx[i].first)]);
        cout<<s[i];
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}