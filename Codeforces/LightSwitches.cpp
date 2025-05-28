#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, te;
void solve(){
    int n,k;cin>>n>>k;
    vector<int> x(n);
    vector<map<int,int>> cnt(k);
    for(int i=0; i<n; i++){
        cin>>x[i];
        cnt[x[i]%k][x[i]/k%2]++;
    }
    for(int i=0; i<k; i++)if(cnt[i][0]>0&&cnt[i][1]>0){cout<<"-1\n";return;}
    sort(x.begin(),x.end());
    int ad = x[0];
    for(int i=0 ;i<n; i++){
        x[i]-=ad;
    }
    int l=0,r=k-1;
    for(int i=1; i<n; i++){
        int p= x[i]/k%2; //0 means left border, 1 means right
        int mo = x[i]%k; 
        if(p){
            r = min((mo+k)%k,r);
        }
        else{
            l = max(l,mo);
        }
    }
    int c = x.back()/k;
    if(c%2==1)c++;
    if(l>r)cout<<"-1\n";
    else cout<<l+ad+c*k<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;te =t;
    while(t--){
        solve();
    }
}