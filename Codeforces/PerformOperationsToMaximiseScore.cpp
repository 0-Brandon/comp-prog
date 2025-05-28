#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, te;
void solve(){
    int n, k;cin>>n>>k;
    vector<int> a(n),b(n),s(n);
    for(int i=0; i<n; i++){
        s[i]=i;
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    sort(s.begin(),s.end(),[&](int i, int j){return a[i]==a[j]?b[i]<b[j]:a[i]<a[j];});
    vector<int> ax, bx;
    vector<int> rev(n);
    for(int i=0; i<n; i++){
        ax.push_back(a[s[i]]);
        bx.push_back(b[s[i]]);
        rev[s[i]] = i;
    }
    vector<int> ap(n+1),bp(n+1);
    for(int i=0; i<n; i++){
        ap[i+1] = ap[i]+((bx[i]==0)?(0):(ax[i]));
        bp[i+1]=bp[i]+bx[i];
    }
    //rev[i] gives the place of the ith index in sorted order
    int ma = (n-1)/2;
    int ans = 0;
    for(int i=0; i<n; i++){
        int m = ma;
        if(rev[i]>=ma){
            //we are greater, median shifts down
            if(n%2==1)m=ma-1;
            if(rev[i]==ma&&n%2==0)m=ma+1;
        }
        else if(rev[i]<ma){
            //we are less, median shifts up
            m = ma+(n%2==0);
        }
        if(b[i]==0){
            int l=ax[m], h = ax.back();
            while(l<h){
                int mid = (l+h+1)/2;
                //we want mid to be median
                //we need (n+1)/2 elements greater than or equal to mid
                auto it=lower_bound(ax.begin(),ax.end(),mid);
                if(it!=ax.begin())it--;
                int id = distance(ax.begin(),it);
                int needed = (n-1)/2+1-(n-1-id-1);
                //we have n-id above already
                //ap contains prefix but only the ones we can increase
                int bl=0,bh = id;
                while(bl<bh){
                    int bm = (bl+bh+1)/2;
                    if(bp[id+1]-bp[bm]>=needed)bl = bm;
                    else bh = bm-1;
                }
                int lef = mid*needed-(ap[id+1]-ap[bl]);
                int bs = bp[id+1]-bp[bl];
                if(lef<=k&&bs>=needed)l=mid;
                else h=mid-1;
            }
            ans=max(ans,a[i]+l);
        }else{
            ans = max(ans,a[i]+k+ax[m]);
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;te=t;
    while(t--){
        solve();
    }
}