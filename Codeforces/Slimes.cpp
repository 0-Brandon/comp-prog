#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n),prev(n),nxt(n),pref(n+1);
    for(int i=0; i<n; i++){
        cin>>x[i];
        pref[i+1] = pref[i]+x[i];
    }
    prev[0]=-1;
    nxt.back()=INT_MAX;
    for(int i=1; i<n; i++){
        if(x[i]==x[i-1])prev[i]=prev[i-1];
        else prev[i]=i-1;
    }
    for(int i=n-2; i>=0; i--){
        if(x[i]==x[i+1])nxt[i]=nxt[i+1];
        else nxt[i] = i+1;
    }
    for(int i=0; i<n; i++){
        int l=-1, h=i;
        while(l<h){
            int m = l+(h-l+1)/2;
            if(pref[i]-pref[m]>x[i])l=m;
            else h = m-1;
        }
        int lans = l; 
        if(lans!=-1&&i-lans==1&&x[lans]==x[i])lans = prev[lans]; //1 1
        else if(lans!=-1&&i-lans>1&&nxt[lans]>=i) lans = prev[lans];//1 1 1
        if(lans<0)lans = INT_MIN;
        l = i,h = n;
        while(l<h){
            int m = l+(h-l)/2;
            if(pref[m]-pref[i+1]>x[i])h = m;
            else l = m+1;
        }
        int inc = 1;
        if(pref[l]-pref[i+1]<=x[i])l=INT_MAX;
        if(l-1<n&&l-i-1==1 && x[i]==x[l-1]) l =nxt[l-1],inc=0; //1 1
        if(l-1<n&&prev[l-1]<=i&&l-1-i>1)l = nxt[l-1],inc=0; // 1 1 1
        int ans = min(i-lans,l-i-inc);
        if(lans<0&&l>=n+10)ans=-1;
        cout<<ans<<" ";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}