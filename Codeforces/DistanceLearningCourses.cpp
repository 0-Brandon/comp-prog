#include <bits/stdc++.h>

using namespace std;

struct SegTree{
    int n;
    vector<int> e;
    SegTree(int n):n(n),e(2*n){}
    void upd(int i, int j){
        for(e[i+=n]=j; i>>=1;){
            e[i] = e[i*2]|e[i*2|1];
        }
    }
    int query (int l, int r){
        int ans = e[r+=n];
        for(l+=n; l<r; l/=2,r/=2){
            if(l&1)ans|=e[l++];
            if(r&1)ans|=e[--r];
        }
        return ans;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> x(n), y(n),w(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        if(x[i]==y[i]){
            w[i]=x[i];
            x[i]=y[i]=0;
            continue;
        }
        int mask = (1<<(__lg(x[i]^y[i])+1))-1;
        w[i] = y[i]-(y[i]&mask);
        y[i] &= mask;
        x[i] &= mask;
    }
    vector<vector<int>> pref(31,vector<int>(n+1));
    SegTree seg(n);
    for(int i=0; i<n; i++){
        seg.upd(i,w[i]);
        for(int j=0; j<31; j++){
            pref[j][i+1] = pref[j][i];
            if(y[i]>>j&1)pref[j][i+1]++;
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        int ans = seg.query(l,r-1);
        for(int i=30; i>=0; i--){
            int cnt = pref[i][r]-pref[i][l]+(ans>>i&1);
            if(cnt>1){
                ans|=(2<<i)-1;
                break;
            }
            if(cnt==1){
                ans|=1<<i;
            }
        }
        cout<<ans<<" ";
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