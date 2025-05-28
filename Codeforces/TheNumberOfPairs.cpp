#include <bits/stdc++.h>

using namespace std;

vector<int> lp(2e7+10),val(2e7+10);
vector<int> pr;
void solve(){
    int c, d, x;
    cin>>c>>d>>x;
    int ans = 0;
    for(int i=1; i*i<=x; i++){
        if(x%i!=0)continue;
        if((x/i+d)%c==0)ans += 1<<val[(x/i+d)/c];
        if(i*i==x)continue;
        if((i+d)%c==0)ans+=1<<val[(i+d)/c];
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    lp[1]=1;
    for(int i=2; i<2e7; i++){
        if(lp[i]==0){
            lp[i]=i;
            pr.push_back(i);
        }
        for(int j=0; i*pr[j]<=2e7; j++){
            lp[i*pr[j]]=pr[j];
            if(pr[j]==lp[i])break;
        }
    }
    for(int i=2; i<=2e7; i++){
        val[i] = val[i/lp[i]]+(lp[i]!=lp[i/lp[i]]);
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}