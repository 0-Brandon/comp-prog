#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    set<int> bad;
    string s;
    cin>>s;
    for(int i=1; i<=n; i++){
        if(i%2!=(s[i-1]=='(')){
            bad.insert(i);
        }
    }
    for(int i=0; i<q; i++){
        int idx;
        cin>>idx;
        if(bad.count(idx))bad.erase(idx);
        else bad.insert(idx);
        if(n&1)cout<<"No\n";
        else if(bad.size()&&((*(bad.begin())&1)||(*(bad.rbegin())%2==0)))cout<<"No\n";
        else cout<<"YEs\n";
    }
}