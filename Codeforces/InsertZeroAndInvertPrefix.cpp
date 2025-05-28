#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    if(a.back()!=0){cout<<"NO\n";return;}
    cout<<"YES\n";
    int idx = n-1;
    while(idx>=0){
        while(idx-1>=0&&a[idx-1]!=1){
            cout<<0<<" ";
            idx--;
        }
        int cnt=0;
        int nidx=idx-1;
        for(int i=idx-1; a[i]==1&&i>=0; i--){
            nidx--;
            cout<<0<<" ";
            cnt++;
        }
        cout<<cnt<<" ";
        idx=nidx;
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