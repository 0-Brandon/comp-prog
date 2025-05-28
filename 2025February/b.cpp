#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 1e9+7;
int expo(int a, int b){
    int ans = 1;
    for(;b;b/=2,a = a*a%mod)if(b&1)ans = ans*a%mod;
    return ans;
}
struct inv{
    int l, r, bit;
};
int get(vector<inv>& invs, int i){
    int l = 0, h = invs.size()-1;
    int ans = invs.size();
    while(l<=h){
        int mid = (l+h)/2;
        if(invs[mid].r>=i)ans = mid, h = mid-1;
        else l = mid+1;
    }
    return ans;
}
int total(vector<inv>& invs, int l, int r){
    int ans = 0;
    int idx = get(invs, l);
    for(; idx<invs.size(); idx++){
        if(invs[idx].l>r) break;
        int a=max(invs[idx].l,l);
        int b=min(invs[idx].r,r);
        if(a<=b&&invs[idx].bit==1)ans+=(b - a + 1);
    }
    return ans;
}
int n, m, q;
int query(vector<inv>& invs, int l, int r, int k){
    int cnt= total(invs,l,r);
    if(cnt>=k)return (expo(2,k)-1+mod)%mod;
    int ans = 0;
    int re = k;
    int pos = l;
    while(re>0&&pos<=r){
        int far = r-re+1;
        int idx = get(invs,pos);
        bool f = false;
        int c = r+1;
        while(idx<invs.size()&&invs[idx].l<=far){
            if(invs[idx].bit==1){
                c = max(pos,invs[idx].l);
                if(c<=far){
                    f = true;
                    break;
                }
            }
            idx++;
        }
        if(f){
            int en = min(invs[idx].r,far);
            int x = en-c+1;
            if(x>re)x=re;
            int add = (expo(2,re)-expo(2,re-x)+mod)%mod;
            ans = (ans+add)%mod;
            re-=x;
            pos = c+x;
        }
        else{
            pos++,re--;
        }
    }
    return ans%mod;
}
signed main(){
    cin>>n>>m>>q;
    vector<int> x;
    x.push_back(1);
    x.push_back(n+1);
    vector<pair<int,int>> upd(m);
    for(int i=0; i<m; i++){
        cin>>upd[i].first>>upd[i].second;
        x.push_back(upd[i].first);
        x.push_back(upd[i].second);
    }
    struct que{int l,r,k;};
    vector<que> qu(q);
    for(int i=0; i<q; i++){
        cin>>qu[i].l>>qu[i].r>>qu[i].k;
        x.push_back(qu[i].l);
        x.push_back(qu[i].r+1);
    }
    sort(x.begin(),x.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    int s = x.size();
    vector<int> dif(s,0);
    for(int i=0; i<m; i++){
        int idx = lower_bound(x.begin(), x.end(), upd[i].first) - x.begin();
        dif[idx] +=1;
        idx = lower_bound(x.begin(), x.end(), upd[i].second+1) - x.begin();
        if(idx<s)dif[idx]-=1;
    }
    vector<int> flips(s,0);
    flips[0] = dif[0];
    for(int i=1; i<s; i++)flips[i] = flips[i-1]+dif[i];
    vector<inv> invs;
    for(int i=0; i<s-1; i++){
        int ls = x[i];
        int rs = x[i+1]-1;
        int bit = flips[i]&1;
        if(ls<=rs){
            if(!invs.empty()&&invs.back().bit==bit&&invs.back().r+1==ls)
                invs.back().r = rs;
            else invs.push_back({ls,rs,bit});
        }
    }
    for(int i=0; i<q; i++){
        cout<<query(invs,qu[i].l,qu[i].r,qu[i].k)<<"\n";
    }
}