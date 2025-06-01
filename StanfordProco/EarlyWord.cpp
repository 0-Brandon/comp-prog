#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int k;cin>>k;
    string s;
    cin>>s;
    int n = s.size();
    string ans = "";
    for(int i=0; i<n; i++){
        int dif = min('a'+26-s[i], s[i]-'a');
        if(k>=dif){
            ans+='a';
            k-=dif;
        }
        else if(k>0){
            ans+=s[i]-k;k=0;
        }
        else{
            ans+=s[i];
        }
    }
    cout<<ans<<"\n";
}