#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n;i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int j = n-1;
    int c = 0;
    int ans = 0;
    for(int i=0; i<n;){
        if(i>j)break;
        if(i==j){
            int dif = x[j]-c;
            if(x[j]==1)ans+=1;
            else ans+=(dif+1)/2+1;
            break;
        }else{
            int a = x[j]-c;
            if(a<=x[i]){
                if(a==x[i])i++;
                else x[i]-=a;
                ans+=x[j]-c+1;
                j--;
                c=0;
            }else{
                ans+=x[i];
                c+=x[i];
                i++;
            }
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}