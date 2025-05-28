#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int pn, xn, d;
    cin>>pn>>xn>>d;
    vector<pair<int,int>> p(pn), x(xn);
    for(int i=0; i<pn; i++){
        cin>>p[i].first>>p[i].second;
    }
    for(int i=0; i<xn; i++){
        cin>>x[i].first>>x[i].second;
    }
    sort(x.begin(),x.end(),[&](pair<int,int> i, pair<int,int> j){return (i.first==j.first)?(i.second<j.second):(i.first>j.first);});
    sort(p.begin(),p.end(), [&](pair<int,int> i, pair<int,int> j){return (i.first==j.first)?(i.second<j.second):(i.first>j.first);});
    vector<int> pre(pn+1);
    vector<int> pres(pn+1);
    for(int i=0 ;i<pn; i++){
        pre[i+1]=pre[i]+p[i].second;
        pres[i+1]=pres[i]+p[i].first;
    }
    int pr = 0;
    int prs=0;
    int ans = 0;
    for(int i=0; i<xn; i++){
        pr+=x[i].second;
        prs+=x[i].first;
        auto it = lower_bound(pre.begin(),pre.end(),d-pr);
        int idx = distance(pre.begin(),it);
        if(it==pre.end())idx = pre.size()-1;
        else if(it!=pre.end()&&*it!=d-pr)idx--;
        if(idx<=0)continue;
        ans = max(ans, prs+pres[idx]);
    }
    cout<<ans<<"\n";
}