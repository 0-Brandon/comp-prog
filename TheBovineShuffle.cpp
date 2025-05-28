#include <bits/stdc++.h>

using namespace std;

void solve (vector<int>& s, vector<int> & o){
    int n= s.size();
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[i]=o[s[i]];
    }
     o=ans;
}
int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> shuffle(n), order(n);
    for(int i=0; i<n; i++){
        cin>>shuffle[i];
        shuffle[i]--;
    } 
    for(int i=0; i<n; i++){
        cin>>order[i];
    }
    solve(shuffle, order); 
    solve(shuffle, order); 
    solve(shuffle, order);
    for(int i=0; i<n; i++){
        cout<<order[i]<<"\n";
    }
}