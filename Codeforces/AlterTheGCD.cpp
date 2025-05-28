#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;cin>>n;
    vector<int> a(n+2,0), b(n+2,0);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=n; i++){
        cin>>b[i];
    }
    for(int i=1; i<=n; i++){
        prefa[i] = prefa[i-1]+a[i];
        prefb[i] = prefb[i-1]+b[i];
    }
    for(int i=n; i>=0; i--){
        sufa[i] = sufa[i+1]+a[i];
        sufb[i] = sufb[i+1]+b[i];
    }
    //l and r go from 1 to n
    auto dfs = [&] (auto&& dfs, int l, int r)->pair<int,int> {
        //answer if we can only swap from l to r
        int ans=0, cnt=0;
        if(l==r){
            ans = gcd(gcd(prefa[l-1],sufa[r+1]),b[l])+
                        gcd(gcd(prefb[l-1],sufb[r+1]),a[l]);
            retrun {ans,1};
        }
        int  mid = (l+r)/2;
        auto ans1 = dfs(dfs, l,mid),ans2 = dfs(dfs,mid+1,r);
        if(ans1.first>ans2.first)ans = ans1.first,cnt = ans1.second;
        else if(ans1.first<ans2.first)ans = ans2.first,cnt = ans2.second;
        else ans = ans1.first,cnt = ans1.second+ans2.second;

        //iterate over the indices where gcd(l,mid) differ from gcd(l+1,mid)
        //and the indices where gcd(mid,r) differ from gcd(mid,r-1);
        int al=0,ag=0,bl=0,bg=0;
        vector<int> rid;
        for(int i=mid+1; i<=r; i++){
            ag = gcd(ag,a[i]);
            bg = gcd(bg,b[i]);
            if(ag!=al||bg!=bl)rid.push_back(i);
            al = ag, bl = bg;
        }
        al=0,ag=0,bl=0,bl=0;
        vector<int> lid;
        for(int i=mid; i>=l; i--){
            ag = gcd(ag,a[i]);
            bg = gcd(bg,b[i]);
            if(ag!=al||bg!=bl)lid.push_back(i);
            al = ag, bl = bg;
        }
        map<int,int> mp;
        for(auto& i:lid){
            for(auto& j:rid){
                mp[gcd(prefa[i-1],gcd(sufa[j+1],gcdb(i...j)))+gcd(prefb[i-1],gcd(sufb[j+1],gcd(i...j)))]++;
            }
        }
        if(mp.rbegin()->first>ans)return *mp.rbegin();
        if(mp.rbegin()->first==ans)return {ans,cnt+mp.rbegin()->second};
        return {ans,cnt};
    };
    auto [ans,cnt] = dfs(dfs,1,n);
    cout<<ans<<" "<<cnt<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}