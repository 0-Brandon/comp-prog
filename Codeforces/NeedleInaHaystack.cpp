#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s, t;
    cin>>s>>t;
    string c = s, d = t;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    string a="",b="";
    int id =0;
    for(int i=0 ; i<d.size(); i++){
        if(d[i]==c[id]){
            a+=d[i];
            id++;
        }
        else{
            b+=d[i];
        }
    }
    if(a!=c){
        cout<<"Impossible\n";
        return;
    }
    merge(s.begin(), s.end(), b.begin(), b.end(), ostream_iterator<char>(cout,""));
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}