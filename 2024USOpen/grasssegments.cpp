#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
signed main(){
    int n;
    cin>>n;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> tl;
    vector<int> l(n),r(n),k(n);
    vector<array<int,4>> inn;
    for(int i=0; i<n; i++){
        cin>>l[i]>>r[i]>>k[i];
        inn.push_back({l[i],r[i],k[i],i});
        tl.push(make_tuple(l[i],1,i));
        tl.push(make_tuple(r[i],-1LL,i));
    }
    ordered_set starts, ends,s,t;
    vector<int> ans(n);
    while(!tl.empty()){
        vector<tuple<int,int,int>> cur;
        auto[ii,ity,iid]=tl.top();
        cur.push_back(tl.top());tl.pop();
        while(!tl.empty()&&get<0>(tl.top())==ii&&get<1>(tl.top())==ity){
            cur.push_back(tl.top());tl.pop();
        }
        for(auto&[i,ty,id]:cur){
            if(ty==-1){
                //the ones that start here and end past i+k[id]
                ans[id]+=starts.order_of_key({i-k[id]+1,-1});
            }else{
                //the ones that start earlier than i-k[id] and end later
                ans[id]+=ends.size()-ends.order_of_key({i+k[id]-1,INT_MAX}); 
            }
        }
        for(auto&[i,ty,id]:cur){
            if(ty==-1){
                starts.erase(starts.find({l[id],id}));
                ends.erase(ends.find({r[id],id}));
            }
            else{
                starts.insert({l[id],id});
                ends.insert({r[id],id});
            }
        }
        //this part double counts if we are contained in bigger one
    }
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int i, int j){if(l[i]==l[j])return r[i]>r[j];return l[i]<l[j];});
    for(auto& i:ord){
        ans[i]-=s.size()-s.order_of_key({r[i],-1});//all of the ones that include us were double counted
        s.insert({r[i],i});
    }
    sort(inn.begin(),inn.end());
    for(auto& [li,ri,ki,i]:inn){
        int id = lower_bound(inn.begin(),inn.end(),array<int,4>{li,-1LL,-1LL,-1LL})-inn.begin();
        bool b= true;
        while(id<n&&inn[id][1]<=ri){
            if(inn[id][1]==ri){id++;continue;}
            if(inn[id][1]-inn[id][0]>=ki)ans[i]++;
            id++;
        }
    }
    for(auto& i:ans)cout<<i-1<<"\n";
}