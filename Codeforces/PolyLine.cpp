#include <bits/stdc++.h>

using namespace std;
void solve(){
    vector<pair<int,int>> x(3);
    for(int i=0; i<3; i++)cin>>x[i].first>>x[i].second;
    sort(x.begin(),x.end());
    if((x[0].first==x[1].first&&x[1].first==x[2].first)||(x[0].second==x[1].second&&x[1].second==x[2].second)){
        cout<<1;
        return;
    }
    do{
        if(
            (x[0].first==x[1].first&&
        (x[2].second>=max(x[0].second,x[1].second)||x[2].second<=min(x[0].second,x[1].second))
        )
        ||(x[0].second==x[1].second&&
        (x[2].first>=max(x[1].first,x[0].first)||x[2].first<=min(x[0].first,x[1].first))
        
        ))
        {
            cout<<2;return;
        }
    }while(next_permutation(x.begin(),x.end()));
    cout<<3;
}
int main(){
    solve();
}