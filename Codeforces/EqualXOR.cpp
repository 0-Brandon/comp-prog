#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    map<int,vector<int>> one, two;
    vector<int> x(n),y(n);
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        cin>>x[i];
        cnt[x[i]]++;
    }
    for(auto& [i,j]:cnt){
        one[j].push_back(i);
    }
    cnt.clear();
    for(int i=0; i<n; i++){
        cin>>y[i];
        cnt[y[i]]++;
    }
    for(auto& [i,j]:cnt){
        two[j].push_back(i);
    }
    sort(one[1].begin(),one[1].end());
    sort(two[1].begin(),two[1].end());
    auto oi =one[2].begin();
    auto ti =two[2].begin();
    int c=0;
    vector<int> a1, a2;
    bool b= true;
    while(c<2*k){
        if(b&&(oi==one[2].end()||ti==two[2].end())){
            oi = one[1].begin();
            ti = two[1].begin();
            break;
        }
        else{
            a1.push_back(*oi);
            a1.push_back(*oi);
            a2.push_back(*ti);
            a2.push_back(*ti);
            c+=2;
            oi++;
            ti++;
        }
    }
    while(c<2*k){
        a1.push_back(*oi);
        a2.push_back(*ti);
        c++;
        oi++;
        ti++;
    }
    for(auto& i:a1)cout<<i<<" ";cout<<"\n";
    for(auto& i:a2)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}