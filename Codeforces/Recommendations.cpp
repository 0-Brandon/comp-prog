/*sort them by l value, and r value

then, add in the intervals as we go along left to right

we want the bottom most interval that is higher, we can keep a list of y vals, then binary search for our y val to find smallest
and we want the right most interval above the element
we can keep a set of the form {height, x-val} as we go along
make sure x-val is always increasing as height decreases
x-val should decrease as height increases 
then, we just search for height, and that x-val is guaranteed to be the answer


EDGE CASE if two intervals are exactly the same!*/

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> intervals(n);
    map<pair<int,int>, int> mp;
    for(int i=0; i<n; i++){
        cin>>intervals[i].first>>intervals[i].second;
        mp[intervals[i]]++;
    }
    set<int> yvals;
    set<pair<int,int>> s;
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    vector<int> aa(n);
    sort(ord.begin(),ord.end(),[&](auto i, auto j){return intervals[i].first==intervals[j].first?intervals[i].second>intervals[j].second:intervals[i].first<intervals[j].first;});
    for(auto& kk:ord){
        auto i = intervals[kk];
        auto botit = yvals.lower_bound(i.second);
        auto rightit = s.lower_bound({i.second,-1});
        if(mp[i]>1)aa[kk] = 0;
        else if(botit!=yvals.end()&&rightit!=s.end()){
            int bot = *yvals.lower_bound(i.second);
            int right = s.lower_bound({i.second,-1})->second;
            int ans = bot-right-(i.second-i.first);//the interval may be +1
            aa[kk] = ans;
        }
        else{
            aa[kk] = 0;
        }
        yvals.insert(i.second);
        auto it = s.lower_bound({i.second+1,-1});//first element that is higher than us (we can't replace them)
        if(it!=s.begin())it--;
        //i.second is the height
        //i.first is the x val
        while(!s.empty()&&it->first<=i.second&&it->second<=i.first){
            it = s.erase(it);
            if(it!=s.begin())it--;
        }
        s.insert({i.second,i.first});
    }
    for(auto& i:aa)cout<<i<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}