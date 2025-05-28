#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, c;
    cin>>n>>c;
    vector<int> bst(c+1,0);
    for(int i=0; i<n; i++){
        int t, d, h;
        cin>>t>>d>>h;
        bst[t]=max(bst[t],d*h);
    }
    for(int i=1; i<=c; i++){
        for(int j=1; j*i<=c; j++){
            bst[j*i] = max(bst[j*i], bst[i]*j);
        }
    }
    for(int i=1; i<=c; i++){
        bst[i]=max(bst[i],bst[i-1]);
    }
    int q;
    cin>>q;
    while(q--){
        int d, h;
        cin>>d>>h;
        int idx = distance(bst.begin(),upper_bound(bst.begin(),bst.end(),d*h));
        int ans = -1;
        if(idx<=c)ans = idx;
        cout<<ans<<" ";
    }
}