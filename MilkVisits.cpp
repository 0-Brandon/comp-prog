#include <bits/stdc++.h>

using namespace std;

struct dsu{
    vector<int> y;
    dsu(int n){
        y= vector<int>(n,-1);
    }
    void unite(int a, int b){
        a=get(a), b=get(b);
		if (a != b){
		    if (y[a] > y[b]) swap(a,b);
		    y[a] += y[b]; 
            y[b] = a;
        }
    }
    
    int get(int a){
        return y[a] < 0 ? a : y[a]=get(y[a]);
    }
    bool same(int a, int b){
        return get(a)==get(b);
    }
};

int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    dsu y(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        if(s[a]==s[b]){
            y.unite(a,b);
        }
    }
    for(int i=0; i<m; i++){
        int a, b;
        char c;
        cin>>a>>b>>c;
        a--,b--;
        if(!y.same(a,b)){
            cout<<1;
        }else{
            cout<<to_string(s[y.get(a)]==c);
        }
    }
}