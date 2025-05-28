#include <bits/stdc++.h>

using namespace std;
struct FT{
    int n;
    vector<int> e;
    FT(int a):n(a),e(a){}
    void upd(int i){
        for(;i<n;i|=i+1)e[i]+=1;
    }
    int query(int i){
        int ans = 0;
        for(;i>0; i&=i-1)ans+=e[i-1];
        return ans;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    FT s(n),s1(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
    }
    vector<int> ans(n,-1);
    for(int i=n-1; i>=0; i--){
        if(i<=x[i]){
            int dist = x[i]-i;
            int nu = 0;
            nu=s.query(x[i]+1)-s.query(i);
            ans[x[i]] = max(0,dist-nu);
            s.upd(x[i]);
        }
    }
    for(int i=n-1; i>=0; i--){
        if(ans[x[i]]!=-1){
            s1.upd(x[i]);
            continue;
        }
        int dist = x[i]+(n-i);
        int nu = s1.query(n)-s1.query(x[i])+s.query(x[i]+1);
        ans[x[i]] = dist-nu;
        s.upd(x[i]);
    }
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}