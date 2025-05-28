#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n  = 0;
int ev(int l, int r){
    int x =0, y = s[l+1]-'0';
    for(int i=l+1; i<r; i+=2){
        int ne=1;
        if(i<r-2) ne=s[i+2]-'0';
        if(s[i+1]=='+'){
            x+=y;
            if(i<r-2)y = s[i+2]-'0';
        }
        else{
            y*=ne;
        }
    }
    return x+y;
}
int solve(int l, int r){
    int x = 0, y = s[0]-'0';
    for(int i=0; i<n; i+=2){
        int ne=1;
        if(i<n-2) ne=s[i+2]-'0';
        if(i+1==l){
            ne = ev(l,r);
            y = y*ne;
            i = r-3;
        }
        else if(s[i+1]=='+'){
            x+=y;
            if(i<n-2)y = s[i+2]-'0';
        }
        else {
            y*=ne;
        }
    }
    return x+y;
}
signed main(){
    cin>>s;
    s = "1*"+s+"*1";
    n= s.size();
    vector<int> x;
    for(int i=0; i<n; i++){
        if(s[i]=='*')x.push_back(i);
    }
    int ans = 0;
    for(int i=0; i<x.size(); i++){
        for(int j=i+1; j<x.size(); j++){
            ans = max(ans, solve(x[i],x[j]));
        }
    }
    cout<<ans<<"\n";
}