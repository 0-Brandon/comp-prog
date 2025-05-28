#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<string> x(2);
    cin>>x[0]>>x[1];
    int y = 0;
    int c=1;
    string ans = "";
    for(int i=0; i<n;){
        ans+=x[y][i];
        if(i==n-1&&y==0){
            y++;continue;
        }
        if(y==1){
            i++;continue;
        }
        int a = x[y+1][i], b = x[y][i+1];
        if(b<a)i++,c=1;
        if(a<b)y++;
        if(a==b)c++,i++;
    }
    cout<<ans<<"\n"<<c<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}