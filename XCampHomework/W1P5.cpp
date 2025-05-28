#include <bits/stdc++.h>

using namespace std;
//wavelet !!!
struct wave{
    wave* left, *right;
    int dl, dh;
    vector<int> b;
    wave(decltype(b.begin()) li, decltype(b.end()) ri, int l, int h){
        dl = l, dh = h;
        if(l==h||li>=ri)return;
        int mid = (l+h)/2;
        b.push_back(0);
        for(auto it = li;it!=ri;it++){
            b.push_back(b.back()+((*it)<=mid));
        }
        auto split = stable_partition(li,ri,[&](int i){return i<=mid;});
        left = new wave(li,split, l, mid);
        right = new wave(split,ri,mid+1,h);
    }
    int query(int l, int r, int k){
        if(l>r or dh<=k)return 0;
        if(dl>k)return r-l+1;
        int nl = b[l-1], nr = b[r];
        return left->query(nl+1,nr,k)+right->query(l-nl,r-nr,k);
    }
    ~wave(){delete left;delete right;}
};
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    wave* w = new wave(x.begin(),x.end(),0,*max_element(x.begin(),x.end()));
    int q;
    cin>>q;
    while(q--){
        int l, r, k;
        cin>>l>>r>>k;
        cout<<w->query(l,r,k)<<"\n";
    }
}