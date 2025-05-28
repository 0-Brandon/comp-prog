#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll n, m;
bool test(ll d, vector<pair<ll,ll>>& x){
    ll ncur=n;
    ll last = LONG_MIN;
    for(auto[i,j]:x){
        i=max(last+d,i);
        ll dif = j-i+1;
        ncur-=dif/d;
        last = i+dif;
        if(ncur<=0) return true;
    }
    if(ncur>0) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<pair<ll, ll>> x;
    for(int i=0; i<m; i++){
        ll a,b;
        cin>>a>>b;
        x.push_back({a,b});
    }
    cout<<"sheesh";
    sort(x.begin(),x.end());
    ll high=1e18, low = 0;
    while(low<high){
        ll mid = low+(high-low)/2;
        if(test(mid,x)){
            low = mid;
        }else{
            high = mid-1;
        }
    }
    cout<<low;
}