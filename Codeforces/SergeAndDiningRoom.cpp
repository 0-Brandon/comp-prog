#include <bits/stdc++.h>
//doesn't work 
using namespace std;

struct Seg{
    int n;
    vector<int> e;
    Seg(int i):n(i),e(2*i,0){}
    void upd(int i, int x){
        i+=n;
        e[i]+=x;
        for(;i/=2;){
            e[i]=e[i*2]+e[i*2+1];
        }
    }
    int query(int l,int r=100005){
        int ans=e[r+=n];
        for(l+=n;l<r;l/=2,r/=2){
            if(l&1)ans+=e[l++];
            if(r&1)ans+=e[--r];
        }
        return ans;
    }
};


int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    int ma = 0;
    cin>>n>>m;
    vector<int> x(n),y(m);
    Seg s(1000006);
    for(int i=0; i<n;i++){
        cin>>x[i];
        s.upd(x[i],1);
        ma = max(ma,x[i]);
    }
    for(int i=0; i<m;i++){
        cin>>y[i];
        s.upd(y[i],-1);
        ma=max(ma,y[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int t,i,a;
        cin>>t>>i>>a;
        i--;
        if(t==1){
            s.upd(x[i],-1);
            x[i]=a;
            s.upd(x[i],1);
        }
        else{
            s.upd(y[i],1);
            y[i]=a;
            s.upd(y[i],-1);
        } 
        ma = max({x[i],y[i],ma});

        int l = -1,h = ma;
        while(l<h){
            int mid = l+(h-l+1)/2;
            if(s.query(mid)>0)l=mid;
            else h=mid-1;
            cout<<mid<<" "<<s.query(mid)<<"\n";
        }
        if(l==-1)cout<<"-1\n";
        else cout<<l<<"\n"; 
    }
}
