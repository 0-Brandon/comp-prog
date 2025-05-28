#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, a, b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int x=0,y=0;
    for(int i=0; i<1000; i++){
        for(int j=0; j<n; j++){
            if(s[j] =='W')x--;
            if(s[j]=='N')y++;
            if(s[j] =='E')x++;
            if(s[j]=='S')y--;
            if(x==a&&y==b){cout<<"YES\n";return;}
        }
    }
    cout<<"NO\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}