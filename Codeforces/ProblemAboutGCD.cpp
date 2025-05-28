#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int L, R, g;
    cin>>L>>R>>g;
    int l = L+((L%g!=0)?(g-(L%g)):0LL);
    int r = R-R%g;
    int aa=-1, bb=-1, d=-1;
    for(int i=0; i<=30&&l+i*g<=1e18; i++){
        for(int j=0; j<=30&&r-j*g>=0; j++){
            int a = l+i*g;
            int b = r-(j*g);
            if(a>b)continue;
            if(gcd(a,b)==g&&abs(a-b)>d)aa=a,bb=b,d=abs(b-a);
        }
    }
    cout<<aa<<" "<<bb<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}