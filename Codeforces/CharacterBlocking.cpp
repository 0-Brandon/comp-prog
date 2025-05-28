#include <bits/stdc++.h>

using namespace std;


void solve(){
    vector<string> s(2);
    cin>>s[0]>>s[1];
    int t, m;
    cin>>t>>m;
    set<int> bad;
    for(int i=0; i<s[0].size(); i++){
        if(s[0][i]!=s[1][i])bad.insert(i);
    }
    queue<pair<int,int>> q;
    for(int i=0; i<m; i++){
        if(q.size()&&i-q.front().second>=t){
            auto[idx,et]=q.front();q.pop();
            if(s[0][idx]!=s[1][idx])bad.insert(idx);
        }
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            b--;
            q.push({b,i});
            if(bad.count(b))bad.erase(b);
        }
        else if(a==2){
            int s1, s2, p1, p2;
            cin>>s1>>p1>>s2>>p2;
            s1--,s2--,p1--,p2--;
            swap(s[s1][p1],s[s2][p2]);
            if(s[0][p1]!=s[1][p1])bad.insert(p1);
            else if(bad.count(p1))bad.erase(p1);
            if(s[0][p2]!=s[1][p2])bad.insert(p2);
            else if(bad.count(p2))bad.erase(p2);
        }
        else{
            cout<<((bad.empty())?("YES\n"):("NO\n"));
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}