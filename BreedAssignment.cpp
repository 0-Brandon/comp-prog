#include <bits/stdc++.h>

using namespace std;
bool check(vector<char>& d, vector<pair<int,int>>& x, string subs){
    for(int i=0; i<d.size(); i++){
        if(d[i]=='S'&&subs[x[i].first-1]!=subs[x[i].second-1]) return false;
        if(d[i]=='D'&&subs[x[i].first-1]==subs[x[i].second-1]) return false;
    }
    return true;
}
void subsets(int n, vector<char>& d, vector<pair<int,int>>& x, string subs,int& ans){
    if(subs.size()==n){
        if(check(d,x,subs))ans++;
        return;
    }
    for(int i='G'; i<='J'; i++){
        if(i=='I') continue;
        subsets(n,d,x,subs+string(1,i),ans);
    }
}
int main(){
    freopen("assign.in", "r", stdin);
    freopen("assign.out", "w", stdout);
    int n,k;
    cin>>n>>k;
    vector<char> d(k);
    vector<pair<int,int>> x(k);
    for(int i=0; i<k; i++){
        cin>>d[i]>>x[i].first>>x[i].second;
    }
    int ans = 0;
    subsets(n,d,x,"H",ans);
    cout<<ans*3;
}