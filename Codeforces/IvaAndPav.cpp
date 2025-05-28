#include <bits/stdc++.h>

using namespace std;

struct Seg{
    int n;
    vector<int> e;
    Seg(vector<int>& a):n(a.size()),e(2*n){
        for(int i = n; i<2*n; i++)e[i]=a[i-n];
        for(int i=n-1; i>0; i--)e[i]=e[i*2]&e[i*2+1];
    }
    int query(int l, int r){
        int ans = e[r+=n];
        for(l+=n; l<r; l>>=1,r>>=1){
            if(l&1)ans&=e[l++];
            if(r&1)ans&=e[--r];
        }
        return ans;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    Seg seg(x);
    int q = 0;cin>>q;
    while(q--){
        int l, k;cin>>l>>k;
        l--;
        int low = l-1, high = n-1; 
        while(low<high){
            int mid = (low+high+1)/2;
            if(seg.query(l,mid)>=k){
                low = mid;
            }else{
                high = mid-1;
            }
        }
        if(low>=l&&seg.query(l,low)>=k)cout<<low+1;
        else cout<<-1;
        cout<<" ";
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