#include <bits/stdc++.h>
 
using namespace std;

struct Segtree{
    int n;
    vector<int> e;
    Segtree(vector<int>& a):n(a.size()),e(2*n){
        for(int i=n; i<2*n; i++){
            e[i] = a[i-n];
        }
        for(int i=n-1; i>0; i--){
            e[i]=gcd(e[i*2], e[i*2+1]);
        }
    }
    int query(int l, int r){
        int ans = e[r+=n];
        for(l+=n;l<r;l/=2,r/=2){
            if(l&1)ans = gcd(ans,e[l++]);
            if(r&1)ans = gcd(ans, e[--r]);
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int> s(n,-1);
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    Segtree st(x);
    for(int i=0; i<n; i++){
        int l = i-1, h =n-1;
        while(l<h){
            int mid = l+(h-l+1)/2;
            if(st.query(i,mid)>mid-i){
                l = mid;
            }else{
                h = mid-1;
            }
        }
        if(st.query(i,l)==l-i+1){
            s[l]=i;
        }
    }
    int pi = -1;
    int a = 0;
    for(int i=0; i<n; i++){
        if(s[i]>pi){
            pi = i;
            a++;
        }
        cout<<a<<" ";
    }
}