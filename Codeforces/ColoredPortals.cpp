#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,q;cin>>n>>q;
    vector<string> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<vector<int>> qu(n);
    vector<pair<int,int>> ref;
    for(int i=0; i<q; i++){
        int a, b;cin>>a>>b;
        a--,b--;
        ref.push_back({a,b});
        qu[a].push_back(i);
        qu[b].push_back(i);
    }
    vector<int> ans(q,INT_MAX);
    map<string, int> mp;
    for(int i=0; i<n; i++){
        mp[x[i]]=i;
        for(auto& qid:qu[i]){
            int o = (ref[qid].first==i)?(ref[qid].second):(ref[qid].first);
            // cout<<i<<" "<<o<<"\n";
            for(char& c1:x[o]){
                for(char& c2:x[i]){
                    string s = string(1,c1)+string(1,c2);
                    sort(s.begin(),s.end());
                    if(mp.find(s)!=mp.end())ans[qid] = min(ans[qid],abs(o-mp[s])+abs(i-mp[s]));
                }
            }
        }
    }
    mp.clear();
    for(int i=n-1; i>=0; i--){
        mp[x[i]]=i;
        for(auto& qid:qu[i]){
            int o = (ref[qid].first==i)?(ref[qid].second):(ref[qid].first);
            // cout<<i<<" "<<o<<"\n";
            for(char& c1:x[o]){
                for(char& c2:x[i]){
                    string s = string(1,c1)+string(1,c2);
                    sort(s.begin(),s.end());
                    if(mp.find(s)!=mp.end())ans[qid] = min(ans[qid],abs(o-mp[s])+abs(i-mp[s]));
                }
            }
        }
    }
    for(auto& i:ans)if(i>3*n)i=-1;
    for(auto& i:ans)cout<<i<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}