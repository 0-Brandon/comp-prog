#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree{
    int n;
    vector<int> tot, pref, suf, me;
    SegTree(int a):n(a),tot(4*a),pref(4*a),suf(4*a), me(4*a){}
    void upd(int i, int dl, int dh, int id, int x){
        if(dl==dh&&dl==id){
            tot[i]=pref[i]=suf[i]=me[i]=x;return;
        }
        if(dh<id||dl>id)return;
        int mid = (dl+dh)/2;
        int lc = i*2+1,rc=i*2+2;
        upd(lc,dl,mid,id,x);
        upd(rc,mid+1,dh,id,x);
        tot[i] = max({tot[lc],tot[rc],suf[lc]+pref[rc]});
        pref[i] = max(pref[lc],me[lc]+pref[rc]);
        suf[i]=max(suf[rc],suf[lc]+me[rc]);
        me[i] = me[lc]+me[rc];
    }
    array<int,4> query(int i, int dl, int dh, int l, int h){
        if(dh<l||dl>h)return {-1000000000LL,-1000000000LL,-1000000000LL,-1000000000LL};
        if(dl>=l&&dh<=h)return {tot[i],pref[i],suf[i], me[i]};
        int mid = (dl+dh)/2;
        auto le = query(i*2+1,dl,mid,l,h);
        auto re = query(i*2+2,mid+1,dh,l,h);
        array<int,4> ans = {0,0,0,0};
        ans[0] = max({le[0],re[0],le[2]+re[1]});
        ans[3] = le[3]+re[3];
        ans[2] = max(re[2],re[3]+le[2]);
        ans[1] = max(le[1],le[3]+re[1]);
        return ans;
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;cin>>n;
    SegTree s(n);
    for(int i=0; i<n; i++){
        int a;cin>>a;
        s.upd(0,0,n-1,i,a);
    }
    int q;cin>>q;
    for(int i=0; i<q; i++){
        int t, x, y;
        cin>>t>>x>>y;
        if(t==0){
            x--;
            s.upd(0,0,n-1,x,y);
        }else{
            cout<<s.query(0,0,n-1,--x,--y)[0]<<"\n";
        }
    }
}