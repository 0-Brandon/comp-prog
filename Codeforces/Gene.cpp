#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

using namespace std;

//2e9
constexpr int N = 5e4+1;
struct node {
    bitset<N> b;
    vector<int> next;
    node():next(4,-1){}
};
constexpr int NN = 1e4;
node trie[NN];
node rtrie[NN];
int main(){
    cin.tie(0)->sync_with_stdio(false);
    map<char,short> mp;
    mp['A'] = 0;
    mp['U'] = 1;
    mp['G'] = 2;
    mp['C'] = 3;
    short cnt[2];cnt[0]=cnt[1]=1;
    auto add = [&](vector<short>& s, int id, node* trie, int ss)->void {
        int v = 0;
        for(auto& c:s){
            if(trie[v].next[c]==-1){trie[v].next[c] = cnt[ss]++;}
            v = trie[v].next[c];
            trie[v].b[id]=true;
        }
    };
    auto query = [&](vector<short>& p,vector<short>& q)->int {
        short v = 0;
        for(auto& c:p){
            if(trie[v].next[c]==-1)return 0;
            v = trie[v].next[c];
        }
        bitset<N>& bi = trie[v].b;
        v = 0;
        reverse(q.begin(),q.end());
        for(auto& c:q){
            if(rtrie[v].next[c]==-1)return 0;
            v = rtrie[v].next[c];
        }
        return (bi&rtrie[v].b).count();
    };
    int n, m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin>>s[i];
        vector<short> c;
        for(auto& j:s[i])c.push_back(mp[j]);
        add(c,i,trie,0);
        reverse(c.begin(), c.end());
        add(c,i,rtrie,1);
    }
    for(int i=0; i<m; i++){
        string p, q;
        cin>>p>>q;
        vector<short> s(p.size());
        vector<short> s1(q.size());
        for(int i=0; i<p.size(); i++){
            s[i] = mp[p[i]];
        }
        for(int i=0; i<q.size(); i++){
            s1[i] = mp[q[i]];
        }
        cout<<query(s,s1)<<"\n";
    }
}