#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n),b(n),x(n);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++){
        cin>>b[i];
        x[i] = b[i]-a[i];
    }
    sort(x.begin(),x.end());
    vector<int> pre(n+1),suf(n+1);
    for(int i=0; i<n; i++){
        pre[i+1] = pre[i]+x[i];
    }
    for(int i=n-1; i>=0; i--){
        suf[i] = suf[i+1]+x[i];
    }
    //l is inclusive, r is not
    int l = k-1, r = n-1;
    int ans = LLONG_MAX;
    int lsu=0, rsu=0;
    int p = n-1;
    for(int i=1e6; i>=-1e6; i--){
        while(p>0&&x[p]>i)p--;
        //p is last elements less than or equal to i;
        while(l>-1&&i-x[l]<x[r]-i){
            l--,r--;
        }
        int right = suf[p+1]-(i*(n-(p+1)));
        int left = i*(p+1)-pre[p+1];
        lsu = i*(l+1)-pre[l+1];
        rsu = suf[r+1]-i*(n-(r+1));
        left-=lsu;
        right-=rsu;
        //cout<<i<<" "<<p<<" "<<l<<" "<<r<<" "<<lsu<<" "<<rsu<<" "<<left<<" "<<right<<'\n';
        ans = min(ans,left+right);
    }
    /*
    for(int i=n-1; i>=0; i--){
        if(l>-1&&x[i]-x[l]<x[r]-x[i]){
            l--,r--;
        }
        int right = suf[i]-(x[i]*(n-i));
        int left = x[i]*(i)-pre[i];
        lsu = x[i]*(l+1)-pre[l+1];
        rsu = suf[r+1]-x[i]*(n-(r+1));
        left-=lsu;
        right-=rsu;
        cout<<i<<" "<<x[i]<<" "<<l<<" "<<r<<" "<<lsu<<" "<<rsu<<" "<<left<<" "<<right<<'\n';
        ans = min(ans,left+right);
    }

    */
    cout<<ans<<"\n";
}