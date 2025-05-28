#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c;
    cin>>a>>b>>c;
    if(c!=a+1){cout<<"-1\n";return;}
    int bi = 0;
    int t = a;
    while(t>>=1)bi++;
    if(a==0)bi=-1;
    b-=((1<<(bi+1))-1)-a;
    b=max(b,0);
    cout<<(b+c-1)/(c)+(bi+1)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}