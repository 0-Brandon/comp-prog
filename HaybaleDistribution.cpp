#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    int ma = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        ma = max(ma,x[i]);
    }
    sort(x.begin(),x.end());
    vector<int> pref(n+1,0);
    for(int i=0; i<n; i++){
        pref[i+1] = x[i]+pref[i];
    }
    auto f = [&](int i, int a, int b){
        int id = distance(x.begin(),lower_bound(x.begin(),x.end(),i));
        int left = (i*id-pref[id])*a;
        int right = (pref.back()-pref[id]-i*(n-id))*b;
        return left+right;
    };
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        int l=0, r=ma;
        while(r-l>=3){
            int m1 = l+(r-l)/3;
            int m2 = r-(r-l)/3;
            if(f(m1,a,b)>f(m2,a,b)){
                l=m1;
            }
            else{
                r=m2;
            }
        }
        cout<<min({f(l,a,b),f(l+1,a,b),f(l+2,a,b)})<<"\n";
    }
}