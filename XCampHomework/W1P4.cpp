#include<bits/stdc++.h>

using namespace std;

struct Query{
    char t;
    int val;
};
vector<Query> queries;
vector<int> tree, value, arr;
void update(int pos, int b, int e,int i, int val,int id){
    if(b>e || b>i || e<i) return;
    if(b>=i && e<=i){
        tree[pos] = val;
        value[pos] = queries[id].val;
        return;
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    update(l,b,m,i,val,id);
    update(r,m+1,e,i,val,id);
    tree[pos] = tree[l] + tree[r];
}
int cquery(int pos, int b, int e, int i, int j){
    if(b>e || b>j || e<i) return 0;
    if(b>=i && e<=j){
        return tree[pos];
    }
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    return cquery(l,b,m,i,j) + cquery(r,m+1,e,i,j);
}
int kquery(int pos, int b, int e, int k){
    if(b==e) return value[pos];
    int m = (b+e)/2;
    int l = pos*2;
    int r = l+1;
    if(tree[l]>=k){
        return kquery(l,b,m,k);
    }
    else{
        return kquery(r,m+1,e,k-tree[l]);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    queries.resize(n+1);
    tree.resize(200001*4,0);
    value.resize(200001*4,0);
    arr.resize(n,0);
    for(int i=1; i<=n; i++){
        cin>>queries[i].t>>queries[i].val;
        arr[i-1] = queries[i].val;
    }
    sort(arr.begin(),arr.end());
    map<int, int> mp;
    int val=0;
    for(int i=0; i<n; i++){
        if(mp.find(arr[i])==mp.end())
            mp[arr[i]] = ++val;
    }
    for(int i=1; i<=n; i++){
        if(queries[i].t=='I'){
            update(1,1,val,mp[queries[i].val],1,i);
        }
        else if(queries[i].t=='C'){
            cout<<cquery(1,1,val,1,mp[queries[i].val]-1)<<"\n";
        }
        else if(queries[i].t=='K'){
            if(queries[i].val>tree[1])
                cout<<"invalid\n";
            else{
                cout<<kquery(1,1,val,queries[i].val)<<"\n";
            }
        }
        else{
            update(1,1,val,mp[queries[i].val],0,i);
        }
    }
}