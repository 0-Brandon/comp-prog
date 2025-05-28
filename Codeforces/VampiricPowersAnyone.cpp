#include <bits/stdc++.h>

using namespace std;

struct Trie{
    array<Trie*,2> has={nullptr,nullptr};
};
void insert(Trie* x, int num){
    for(int i=7; i>=0; i--){
        bool bit = (num>>i)&1;
        if(!(x->has[bit]))x->has[bit] = new Trie();
        x=x->has[bit];
    }
}
int query(Trie* x, int num){
    int ans=0;
    for(int i=7; i>=0; i--){
        bool bit = (num>>i)&1;
        if(x->has[!bit]){x=x->has[!bit];ans|=(1<<i);}
        else x=x->has[bit];
    }
    return ans;
}
void solve(){
    Trie* root=new Trie();
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans=0, pref=0;
    insert(root,0);
    for(int i=0; i<n; i++){
        pref^=x[i];
        insert(root, pref);
        ans=max(ans, query(root,pref));
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}