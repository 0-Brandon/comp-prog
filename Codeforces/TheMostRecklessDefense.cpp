#include <bits/stdc++.h>

using namespace std;
constexpr int R = 12;
vector<int> po(R);
void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            grid[i][j] = s[j];
        }
    }
    vector<int> p(k);
    vector<vector<int>> c(k, vector<int>(R,0));
    for(int i=0; i<k; i++){
        int x, y;
        cin>>x>>y>>p[i];
        x--,y--;
        for(int j=0; j<R; j++){
            for(int l = x-j; l<=x+j; l++){
                for(int u = y-j; u<=y+j; u++){
                    if(l<0||l>=n||u<0||u>=m)continue;
                    if(grid[l][u]=='#'&&(l-x)*(l-x)+(u-y)*(u-y)<=j*j)c[i][j]++;
                }
            }
        }
    }
    vector<vector<int>> dp(k, vector<int>(1<<R,0));
    for(int i=0; i<k; i++){
        for(int mask=0; mask<1<<R; mask++){
            if(i>0)dp[i][mask] = dp[i-1][mask];
            for(int b = 0; b<R; b++){
                int sm = 1<<b;
                if(!(mask&sm))continue;
                dp[i][mask] = max(dp[i][mask], (i>0?dp[i-1][mask^sm]:0)+p[i]*c[i][b]);
            }
        }
    }
    auto co = [&](int b){
        int ans = 0;
        for(int i=0; i<R; i++)if((1<<i)&b)ans+=po[i];
        return ans;
    };
    int ans = 0;
    for(int mask=0; mask<1<<R; mask++){
        ans = max(ans,dp.back()[mask]-co(mask));
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    po[0]=1;
    for(int i=1; i<R; i++)po[i]=po[i-1]*3;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}