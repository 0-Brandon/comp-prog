#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    int k;cin>>k;
    for(int i=n-2; i>=0; i--){
        c[i] = min(c[i],c[i+1]);
    }
    vector<int> ans(n,0);
    int left = k%c[0];
    int a = k/c[0];
    ans[0]=a;
    for(int i=1; i<n; i++){
        if(c[i]==c[i-1]){
            ans[i]=a;continue;
        }
        else{
            ans[i]=min(left/(c[i]-c[i-1]),ans[i-1]); 
            if(ans[i-1]>left/(c[i]-c[i-1]))left = left % (c[i]-c[i-1]);
            else left = left-ans[i-1]*(c[i]-c[i-1]);
            a = ans[i];
        }
    }
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}