#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s, t;
    cin>>s>>t;
    int i=0, j=n-1;
    while(s[i]==t[i])i++;
    while(s[j]==t[j])j--;
    if(j==i){cout<<2<<"\n";return 0;}
    int d = j-i;
    int ans = 0;
    if(s.substr(i+1,d)==t.substr(i,d))ans++;
    if(s.substr(i,d)==t.substr(i+1,d))ans++;
    cout<<ans<<"\n";
}