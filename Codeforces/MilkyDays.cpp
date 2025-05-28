#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<array<int,3>> t; //date, amount
    t.push_back({(int)1e6+5, 0});
    for(int i=0; i<n; i++){
        int d, a;cin>>d>>a;
        t.push_back({d,a,i});
        t.push_back({d+k,-a,i});
    }
    sort(t.begin(),t.end());
    //[,)
    int ans = 0;
    int cur = 0;
    int l = -1;
    deque<pair<int,int>> s;
    //amount, batch
    //deque latest<-earliest
    for(auto&[i,a,id]:t){
        int days = cur/m;
        bool b = false;
        if(i-l>days)b=true;
        //this means we will drink all the milk
        days = min(days,(i-l));
        int su=0;
        int tot = days*m;
        while(!s.empty()&&su<tot){
            if(s.front().first+su>tot){
                auto p = s.front();
                s.pop_front();
                s.push_front({p.first-(tot-su),p.second});
                cur-=tot-su;
                su=tot;
            }
            else{
                cur-=s.front().first;
                su+=s.front().first;
                s.pop_front();
            }
            if(su==tot)break;
        }
        if(b){
            s.clear();
            cur=0;
        }
        ans+=days;
        if(a>0){
            s.push_front({a,id});
            cur+=a;
        }
        else{
            if(s.size()&&s.back().second==id){
                cur-=s.back().first;
                s.pop_back();
            }
        }
        l=i;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}