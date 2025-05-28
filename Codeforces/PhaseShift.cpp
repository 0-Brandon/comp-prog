#include <bits/stdc++.h>
//doesn't work
using namespace std;

void solve(){
    int n;cin>>n;
    string t;cin>>t;
    map<char,char> cnt;
    map<char,char> rev;
    string s;
    char letter=  'a';
    for(int i=0; i<n; i++){
        if(cnt.find(t[i])!=cnt.end())s+=cnt[t[i]];
        //cnt[t] goes to t;
        //t goes to rev[t]
        else
        for(char c = 'a'; c<='z'; c++){
            if(c==t[i])continue;
            if(cnt.find(c)!=cnt.end()&&cnt[c]==t[i])continue; //we cannot have cnt[t] == c and cnt[c] ==t
            if(rev.find(c)!=rev.end())continue; //if c already 
            cnt[t[i]] = c;
            rev[c]=t[i];
            s+=c;
            break;
        }
    }
    cout<<s<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}