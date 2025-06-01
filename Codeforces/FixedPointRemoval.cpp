#include <bits/stdc++.h>

using namespace std;
constexpr int LOG = 25;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q;cin>>n>>q;
    vector<int> x(n+1);
    for(int i=1; i<=n; i++){
        cin>>x[i];
        x[i] = i-x[i];
    }
    vector<vector<pair<int,int>>> id(n+1);
    for(int i=0; i<q; i++){
        int l, r;cin>>l>>r;
        r = n-r;
        id[r].push_back({l+1,i});
    }
    vector<int> ans(q);
    vector<int> bit(n+1);
    auto add = [&](int i){
        for(;i<=n; i += i&(-i)){
            bit[i]++;
        }
    };
    auto query = [&](int i){
        int ans = 0;
        for(;i;i-=i&-i)ans+=bit[i];
        return ans;
    };
    int global = 0;
    for(int i=1; i<=n; i++){
        if(x[i]>=0){
            int l = 0;
            int su = global;
            for(int j=LOG; j>=0; j--){
                if(l+(1<<j)<=i&&su-bit[l+(1<<j)]>=x[i]){
                    su-=bit[l+(1<<j)];
                    l +=1<<j;
                }
            }
            //l is the biggest index still greater. 
            global++;
            add(l+1);
        }
        for(auto& [l,qid]:id[i]){
            ans[qid] = global-query(l);
        }
    }
    for(auto& i:ans)cout<<i<<"\n";
}

//number of elements that are greater than ai elements before it in this range