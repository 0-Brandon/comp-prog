#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int ma = 0, mi = INT_MAX;
    int h, w;cin>>h>>w;
    vector<vector<int>> x(h,vector<int>(w));
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>x[i][j];
            ma = max(ma, x[i][j]);
            mi = min(mi, x[i][j]);
        }
    }
    auto ok = [&](int r)->bool {
        int f = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(x[i][j]>mi+r)f=max(f,j+1);
            }
            for(int j=0; j<w; j++){
                if(x[i][j]<ma-r&&j<f)return false;
            }
        }
        return true;
    };
    auto solve = [&]()->int {
        int l=0, h = ma-mi;
        while(l<h){
            int mid = (l+h)/2;
            if(ok(mid)){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    };
    int ans = INT_MAX;
    ans = min(ans,solve());
    reverse(x.begin(),x.end());
    ans = min(ans,solve());
    for(auto& i:x)reverse(i.begin(),i.end());
    ans = min(ans,solve());
    reverse(x.begin(),x.end());
    ans = min(ans,solve());
    cout<<ans<<"\n";
}