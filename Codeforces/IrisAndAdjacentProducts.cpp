#include <bits/stdc++.h>

using namespace std;
//WAVELETTTT!!!!
struct wavelet{
    int dl, dh;
    wavelet* left, *right;
    vector<int> b;
    wavelet(decltype(b.begin()) s, decltype(b.end()) t, int x, int y){
        dl = x, dh = y;
        if(dl==dh||s>=t)return;
        int m = (dl+dh)/2;
        auto f = [&](int i){return i<=m;};
        b.reserve(t-s+1);
        b.push_back(0);
        for(auto it = s; it!=t; it++){
            b.push_back(b.back()+f(*it));
        }
        auto pivot = stable_partition(s,t,f);
        left = new wavelet(s,pivot,dl,m);
        right = new wavelet(pivot,t,m+1,dh);
    }
    int kth(int l, int r, int k){
        if(l>r)return 0;
        if(dl==dh)return dl;
        int lb = b[l-1];
        int rb = b[r];
        int lef = rb-lb;
        if(k<=lef)return left->kth(lb+1,rb,k);
        return right->kth(l-lb,r-rb,k-lef);
    }
};
void solve(){
    int n, q, k;
    cin>>n>>q>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    wavelet* w = new wavelet(x.begin(),x.end(),0,1e6);
    //n 1 n-1 2 n-2 3 n-3 4 n-4 5
    //10 1 9 2 8 3 7 4 6 5 
    //11 1 10 2 9 3 8 4 7 5 6
    //n/2 * n/2+1
    //n/2-1 * n/2+2
    //n/2 * n/2+1
    //n/2-1 * n/2+2
    //binary search smallest value x such that 
    //the (n/2-x)th smallest element * (n/2+x+1)th is greater than k, answer is x+1
    //how to get kth smallest element in range?
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        l--,r--;
        int tn = r-l+1;
        int dl = 0, dh = tn/2-1;
        while(dl<dh){
            int mid = (dl+dh)/2;
            if((w->kth(l,r,tn/2-mid-1))*(w->kth(l,r,tn/2+mid))>k)dh = mid;
            else dl = mid+1;
        }
        cout<<dl<<" ";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();   
}