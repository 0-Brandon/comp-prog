#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> x(3,vector<int>(n));
    int tot = 0;
    for(int i=0; i<n; i++){
        cin>>x[0][i];
        tot+=x[0][i];
    }
    int req = (tot+2)/3;
    for(int i=0; i<n; i++){
        cin>>x[1][i];
    }
    for(int i=0; i<n; i++){
        cin>>x[2][i];
    }
    vector<int> s{0,1,2};
    do{
        vector<pair<int,int>> ans(3);
        int su = 0;
        int id = 0;
        int l =0;
        int b1=0;
        for(int i=0; i<n; i++){
            su+=x[s[id]][i];
            if(su>=req){
                ans[s[id]] = {l,i};
                su = 0;
                l = i+1, id++;
                b1++;
            }
            if(id>=3)break;
        }
        if(b1>=3){
            for(auto& i:ans){
                cout<<i.first+1<<" "<<i.second+1<<" ";
            }
            cout<<"\n";
            return;
        }    
    }while(next_permutation(s.begin(),s.end()));
    cout<<"-1\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){solve();}
}