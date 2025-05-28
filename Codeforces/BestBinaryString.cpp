#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin>>s;
    string ans(s.size(),'.');
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]=='?'){
            if(i==s.size()-1)ans[i]='1';
            else ans[i]=ans[i+1];
        }
        else ans[i]=s[i];
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}