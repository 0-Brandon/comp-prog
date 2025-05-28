#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<long long int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    set<int> ans;
    if(n==2){
        while(x[0]&&x[1]){
            x[1] = max(0LL,x[1]-x[0]);
            x[0] = max(0LL,x[0]-x[1]);
        }
        if(x[0])ans.insert(0);
        if(x[1])ans.insert(1);
    }
    else if (n==3){
        while(x[0]&&x[1]&&x[2]){
            x[1] = max(0LL,x[1]-x[0]);
            x[2] = max(0LL,x[2]-x[1]);
            x[0] = max(0LL,x[0]-x[2]);
        }
        if(x[0]&&!x[2])ans.insert(0);
        if(x[2]&&!x[1])ans.insert(2);
        if(x[1]&&!x[0])ans.insert(1);
    }
    else{
        auto check = [&](){
            for(int i=0; i<n; i++){
                if(x[i]&&x[(i+1)%n]&&x[(i+2)%n]&&x[(i+3)%n])return true;
            }
            return false;
        };
        while(check()){
            for(int i=0; i<n; i++){
                x[(i+1)%n]=max(0LL,x[(i+1)%n]-x[i]);
            }
        }
        int i=0;
        for(;i<n; i++){
            if(x[i]&&x[(i+1)%n])x[(i+1)%n] = max(0LL,x[(i+1)%n]-x[i]);
            else break;
        }
        for(;i<n; i++){
            if(x[i]!=0||x[(i+1)%n]==0)continue;
            ans.insert((i+1)%n);
            long long y2 = x[(i+2)%n], y1 = x[(i+1)%n];
            long long nu = y2/y1;
            if((nu*y2-nu*(nu+1)/2*y1)<x[(i+3)%n])ans.insert((i+3)%n);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto& i:ans)cout<<i+1<<" ";cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}