#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    auto comp = [&](int i, int j, int k){
        return (h[k]-h[i])*(j-i)>=(h[j]-h[i])*(k-i);
    };
    //we keep a set wit all the mountains we can see
    //each set is increasing, because the slopes have to be increasing
    //when we increase a mountain, we increase its entry in the sets before it
    //and invalidate the not seeable ones
    vector<set<int>> s(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].empty())s[i].insert(j);
            else if(comp(i,*s[i].rbegin(),j))s[i].insert(j);
        }
    }
    int q;
    cin>>q;
    while(q--){
        int id=0, a=0;
        cin>>id>>a;
        id--;
        h[id] += a;
        for(int i=0; i<id; i++){
            auto it = s[i].lower_bound(id);
            if(it!=s[i].begin()&&!comp(i,*prev(it),id))continue;
            s[i].insert(id);
            if(it!=s[i].end()&&*it==id)it++;
            while(it!=s[i].end()){
                if(!comp(i, id, *it)){
                    s[i].erase(it++);
                }
                else break;
            }
        }
        s[id].clear();
        for(int i=id+1; i<n; i++){
            if(s[id].empty())s[id].insert(i);
            else if(comp(id,*s[id].rbegin(),i))s[id].insert(i);
        }
        int ans = 0;
        for(int i=0; i<n; i++)ans+=s[i].size();
        cout<<ans<<"\n";
    }
}