#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> x(n);
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first;
        x[i].second=i;
    }
    sort(x.begin(),x.end());
    int r=n-1, l=0;
    int lv=0, rv=n;
    for(int i=n; i>0; i--){
        if((x[r].first==rv)^(x[l].first==lv)){
            if(x[r].first==rv){
                lv++;
                ans[x[r--].second]=i;
            }else{
                rv--;
                ans[x[l++].second]=-i;
            }
        }else{
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(auto& i:ans){
        cout<<i<<" ";
    }cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}