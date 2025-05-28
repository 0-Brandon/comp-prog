#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin>>n;
    int r=1;
    map<int,int> a,b;
    int l=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(l==x)r++;
        else r=1;
        a[x]=max(a[x],r);
        l=x;
    }
    l=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(l==x)r++;
        else r=1;
        b[x]=max(b[x],r);
        l=x;
    }
    int ans=0;
    for(auto& [num,cnt]:a){
        ans=max(ans,cnt+b[num]);
    }
    for(auto& [num,cnt]:b){
        ans=max(ans,cnt+a[num]);
    }
    cout<<ans<<"\n";
}
int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--)solve();
}