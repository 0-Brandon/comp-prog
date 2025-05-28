#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 0;
    auto solve = [&](auto solve, int id, vector<int>& e)->int {
        if(e.size()==1)return 1;
        vector<vector<int>> ne(2);
        for(auto& i:e){
            ne[(x[i]>>id)&1].push_back(i);
        }
        if(ne[0].size()==0){
            return solve(solve,id-1,ne[1]);
        }
        if(ne[1].size()==0){
            return solve(solve,id-1,ne[0]);
        }
        return 1+max(solve(solve,id-1,ne[0]),solve(solve,id-1,ne[1]));
    };
    vector<int> sh(n);
    iota(sh.begin(),sh.end(),0);
    ans = solve(solve,30,sh);
    cout<<n-ans<<"\n";
}