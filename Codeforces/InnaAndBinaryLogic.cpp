#include <bits/stdc++.h>
using namespace std;
const int MM = 20;
int n, m;
struct SegTree{
    vector<int> l,r;
    vector<long long>e;
    vector<int>a;
    SegTree(int n):l(4*n),r(4*n),e(4*n),a(4*n){};
    int val(int i){return i*(i+1)/2;}
    void merge(int id, int i, int j){
        //i<j
        a[id] = a[i]&&a[j];
        e[id] = e[i]+e[j];
        e[id]+=1LL*r[i]*l[j];
        l[id] = l[i];
        r[id]=r[j];
        if(a[i])l[id] = l[i]+l[j];
        if(a[j])r[id] = r[i]+r[j];
    }
    void update(int i,int dl, int dh, int id, int ne){
        if(dl==dh&&dl==id){
            r[i]=l[i]=a[i]=e[i]=ne;
            return;
        }
        if(dl>id||dh<id)return;
        int mid = (dl+dh)/2;
        update(i*2+1,dl,mid,id,ne);
        update(i*2+2,mid+1,dh,id,ne);
        merge(i,i*2+1,i*2+2);
    }
    long long su(){
        return e[0];
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    vector<SegTree> x(MM+1,SegTree(n));
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        for(int j=MM; j>=0;j--){
            x[j].update(0,0,n-1,i, (a>>j)&1);
        }
    }
    while(m--){
        int a, b;
        cin>>a>>b;
        a--;
        for(int i=MM; i>=0; i--){
            x[i].update(0,0,n-1,a,(b>>i)&1);
        }
        long long ans=0;
        for(int i = 0; i<=MM; i++){
            ans+=x[i].su()*(1LL<<i);
        }
        cout<<ans<<"\n";
    }
}