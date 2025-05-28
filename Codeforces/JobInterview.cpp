#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;cin>>n>>m;
    int N = n+m+1;
    vector<array<int,2>> x(N);
    for(int i=0; i<N; i++){
        cin>>x[i][0];
    }
    for(int i=0; i<N; i++)cin>>x[i][1];
    int b=-1;
    vector<int> choice(N);
    vector<int> a(N);
    int cn = 0, cm=0;
    int ans = 0;
    for(int i=0; i<N-1; i++){
        if(x[i][0]>x[i][1]){
            if(cn>=n){choice[i] = 1;if(b==-1)b=i;ans+=x[i][1];}
            else{
                choice[i]=0;ans+=x[i][0],cn++;
            }
        }
        else{
            if(cm>=m){choice[i] = 0;if(b==-1)b=i;ans+=x[i][0];}
            else{
                choice[i]=1;ans+=x[i][1],cm++;
            }
        }
    }
    a[N-1]=ans;
    for(int i=0; i<N-1; i++){
        int cur = ans-x[i][choice[i]];
        if(i<b&&choice[i]!=choice[b]){
            cur += x[b][!choice[b]]-x[b][choice[b]];
            cur += x.back()[!choice[i]];
        }
        else{
            cur+=x.back()[choice[i]];
        }
        a[i] = cur;
    }
    for(auto& i:a)cout<<i<<" ";
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

