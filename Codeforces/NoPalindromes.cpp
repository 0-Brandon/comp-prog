#include <bits/stdc++.h>

using namespace std;

int t;
void solve(){
    string s;
    cin>>s;
    int n = s.size();
    bool b=true;
    for(int i=1; i<n; i++)if(s[i]!=s[i-1])b=false;
    if(b){cout<<"NO\n";return;}
    b=true;
    for(int i=2; i<n; i++)if(s[i]!=s[i-2])b=false;
    if(n%2==1&&b){cout<<"NO\n";return;}
    bool c = true;
    for(int i=0; i<n; i++)if(s[i]!=s[n-i-1])c=false;
    if(!c){cout<<"YES\n1\n"<<s<<"\n";return;}
    vector<string> ans;
    string cur = string{s[0]};
    for(int i=1; i<n; i++){
        cur+=s[i];
        if(s[i]!=s[i-1]&&cur.size()>1){
            ans.push_back(cur);
            cur="";
        }
    }
    if(cur==""){
        cout<<"YES\n"<<ans.size()<<"\n";
        for(auto& i:ans)cout<<i<<" ";cout<<"\n";
        return;
    }
    string nc = ans.back()+cur;
    ans.pop_back();
    b=false;
    for(int i=0; i<nc.size(); i++)if(nc[i]!=nc[nc.size()-i-1])b=true;
    if(b){
        ans.push_back(nc);
    }
    else{
        if(ans.empty()){cout<<"NO\n";return;}
        string nnc = ans.back()+nc;
        ans.pop_back();
        bool f = true;
        for(int i=0; i<nnc.size(); i++)if(nnc[i]!=nnc[nnc.size()-i-1])f=false;
        if(!f)ans.push_back(nnc);
        else{
            ans.push_back(nnc.substr(0,nnc.size()/2-1));
            ans.push_back(nnc.substr(nnc.size()/2-1));
        }
    }
    cout<<"YES\n"<<ans.size()<<"\n";
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}

