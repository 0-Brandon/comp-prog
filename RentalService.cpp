#include <bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    int n, m, rent;
    cin>>n>>m>>rent;
    vector<int> c(n);
    vector<pair<int,int>> qp(m);
    vector<int> r(rent);
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    for(int i=0; i<m; i++){
        cin>>qp[i].first>>qp[i].second;
    }
    for(int i=0; i<rent; i++){
        cin>>r[i];
    }
    sort(qp.begin(),qp.end(), [&](pair<int,int>i,pair<int,int>j){return i.second>j.second||(i.second==j.second&&i.first>j.first);});
    sort(r.begin(),r.end(),std::greater<int>());
    sort(c.begin(),c.end(),std::greater<int>());
    int ri=0;
    int qpi=0;
    int ci = 0;
    int rci=n;
    long long int ans = 0;
    while(ci<rci&&ri<rent&&qpi<m){
        int tempi = qpi;
        int numorders = 0, milkcost=0;
        while(qp[qpi].first+numorders<=c[ci]){
            milkcost += qp[qpi].first*qp[qpi].second;
            numorders += qp[qpi].first;
            qpi++;
        }
        milkcost+=(c[ci]-numorders)*qp[qpi].second;
        if(milkcost>r[ri]){
            ans+=milkcost;
            qp[qpi].first-=c[ci]-numorders;
            c[ci]=0;
            if(c[ci]==0)ci++;
            if(qp[qpi].first==0)qpi++;
        }else{
            qpi=tempi;
            rci--;
            ans+=r[ri++];
        }
    } 
    while(ci<rci&&ri<rent){
        ci++;
        ans+=r[ri++];
    }
    while(ci<rci&&qpi<m){
        int temp = min(qp[qpi].first,c[ci]);
            ans+=temp*qp[qpi].second;
            c[ci]-=temp;
            qp[qpi].first-=temp;
            if(c[ci]==0)ci++;
            if(qp[qpi].first==0)qpi++;
    }
    cout<<ans;
}