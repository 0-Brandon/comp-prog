#include <bits/stdc++.h>
#define int long long
using namespace std;

int t;
void solve(){
    int n;cin>>n;
    vector<array<int,2>> s;
    int ans = 0;
    for(int i=0; i<n; i++){
        int a,b;cin>>a>>b;
        int l = 0;
        int cans = 0;
        while(!s.empty()&&(s.back()[0]-cans<=a||s.back()[1]==b)){
            if(s.back()[1]==b){
                a = s.back()[0]-l+a-l;
                cans+=l;
            }
            l=s.back()[0];
            s.pop_back();
        }
        cans+=a;
        s.push_back({cans,b});
        ans = max(ans,cans);
        cout<<ans<<" ";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--)solve();
}