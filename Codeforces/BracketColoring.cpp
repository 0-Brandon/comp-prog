#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> bal(n,0);
    for(int i=0; i<n; i++){
        if(s[i]=='(')bal[i]=bal[max(i-1,0)]+1;
        else bal[i]=bal[max(i-1,0)]-1;
    }
    vector<int> ans(n);
    if(bal.back()!=0){cout<<"-1\n";return;}
    if((*max_element(bal.begin(),bal.end())==0)||(*min_element(bal.begin(),bal.end())==0)){
        cout<<1<<"\n";
        for(int i=0; i<n; i++)cout<<"1 ";
        cout<<"\n";
        return;
    }
    for(int i=0; i<n;){
        int cur = (s[i]=='(')?1:2;
        while(i<n){
            ans[i++]=cur;
            if(bal[i-1]==0)break;
        }
    }
    cout<<2<<"\n";
    for(auto& i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--)solve();
}