#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> h(n+1);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    h[n] = INT_MAX;
    vector<int> anext(n+1),bnext(n+1),adist(n+1),bdist(n+1);
    anext[n] = n;
    bnext[n] = n;    
    set<pair<int,int>> s;
    s.insert({-2e9,n});
    s.insert({-2e9-1,n});
    s.insert({2e9,n});
    s.insert({2e9+1,n});
    for(int i=n-1; i>=0; i--){
        auto r = s.lower_bound({h[i],-1}), l = prev(r), ch = r, o= r;
        int inc = 0;
        if(r->first-h[i]<h[i]-l->first)bnext[i] = r->second, ch = r, o = l, inc =1;
        else bnext[i] = l->second, ch=l, o =r, inc = -1;
        advance(ch,inc);
        if(abs(ch->first-h[i])<abs(o->first-h[i]))anext[i] = ch->second;
        else anext[i] = o->second;
        s.insert({h[i],i});
    }
    vector<int> atot(n+1),btot(n+1);
    adist[n] = 0;
    bdist[n] = 0;
    for(int i=n-1; i>=0; i--){
        atot[i] = (anext[i]==n?0:abs(h[anext[i]]-h[i]))+btot[anext[i]];
        btot[i] = (bnext[i]==n?0:abs(h[bnext[i]]-h[i]))+atot[bnext[i]];
        adist[i] = (anext[i]==n?0:abs(h[anext[i]]-h[i]))+adist[bnext[anext[i]]];
        bdist[i] = (bnext[i]==n?0:abs(h[bnext[i]]-h[i]))+bdist[anext[bnext[i]]];
    }
    vector<int> aid(n, -1), bid(n,-1);
    vector<int> ind(n);
    vector<vector<int>> strand;
    for(int i=0; i<n; i++){
        if(aid[i]==-1){aid[i] = strand.size();strand.emplace_back();}
        if(bid[i]==-1){bid[i] = strand.size();strand.emplace_back();}
        aid[bnext[i]] = bid[i];//if we are b, then their aid is us 
        bid[anext[i]] = aid[i];//if we are a, then their bid is us
        ind[i] = strand[aid[i]].size();
        strand[aid[i]].push_back(i);
        strand[bid[i]].push_back(i);
    }
    int x0;
    cin>>x0;
    for(auto& i:aid)cout<<i<<" ";
    cout<<"\n";
    for(auto& i:bid)cout<<i<<" ";
    cout<<"\n";
    for(auto&i: strand){for(auto& j:i)cout<<j<<" ";cout<<"\n";}
    for(auto& i:adist)cout<<i<<" ";cout<<"\n";
    for(auto& i:bdist)cout<<i<<" ";
    pair<int,int> ans= {0,0};
    int ansid = 0;
    for(int i=0; i<n; i++){
        int l = ind[i], r = strand[aid[i]].size()-1;
        while(l<r){
            int mid = (l+r+1)/2;
            if((mid-l)%2==1){
                //it wil be btot
                if(atot[i]-btot[strand[aid[i]][mid]]<=x0)l = mid;
                else r = mid-1;
            }else{
                //it wil be atot
                if(atot[i]-atot[strand[aid[i]][mid]]<=x0)l = mid;
                else r = mid-1;
            }
        }
        int c, d;
        if((l-ind[i])%2==1){
            //l is b
            c = adist[i] - adist[bnext[strand[aid[i]][l]]];
            d = bdist[anext[i]] - bdist[strand[aid[i]][l]];
        }
        else{
            //l is a
            c = adist[i] - adist[strand[aid[i]][l]];
            d = bdist[anext[i]] - bdist[anext[strand[aid[i]][l]]];
        }
        if(d==0)c = INT_MAX,d=1;
       // cout<<c<<" "<<d<<"\n";
        if(ans.second*c==d*ans.first&&h[ansid]<h[i]){
            ansid = i;
            ans = {c,d};
        }
        else if(ans.second*c<d*ans.first){
            ansid = i;
            ans = {c,d};
        }
    }
    cout<<ansid+1<<"\n";
    //on our path, figure out which node is farthest we can go without crossing x
    //we kind of can split it into strands actually

    int m;
    cin>>m;
    //start building thre stands from the front
    //now we can just binary search on our strand to check distance x, and 
    for(int i=0; i<m; i++){
        int s, x;
        cin>>s>>x;
        s--;
        //binary serach on our strand to find the place we go to , then just do adist and bdist
        int l = ind[s], r = strand[aid[s]].size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if((mid-l)%2==1){
                //it wil be btot
                if(atot[i]-btot[strand[aid[s]][mid]]<=x)l = mid;
                else r = mid-1;
            }else{
                //it wil be atot
                if(atot[i]-atot[strand[aid[s]][mid]]<=x)l = mid;
                else r = mid-1;
            }
        }
        //we go from s to strand[aid[s]][l]
        int c, d;
        if((l-ind[s])%2==1){
            //l is b
            c = adist[s] - adist[bnext[strand[aid[s]][l]]];
            d = bdist[anext[s]] - bdist[strand[aid[s]][l]];
        }
        else{
            //l is a
            c = adist[s] - adist[strand[aid[s]][l]];
            d = bdist[anext[s]] - bdist[anext[strand[aid[s]][l]]];
        }
        //c is the distance by a, d is the distance by b;
    }

}