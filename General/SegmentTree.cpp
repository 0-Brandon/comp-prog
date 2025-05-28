#include <bits/stdc++.h>

using namespace std;
int n,q;
void build(vector<long long int>& segtree){
    for(int i=n-1; i>=1; i--){
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
}

void set_num(vector<long long int>& segtree,int a,int b){
    int i = n+a-1;
    b = b-segtree[i];
    for(;i>=1; i/=2){
        segtree[i]+=b;
    }
}
long long int query(vector<long long int>& segtree, int a, int b, int low, int high, int i){
    if(high<a||low>b){
        return 0;
    }
    if(high<=b&&low>=a){
        return segtree[i];
    }else{
        int mid = low+(high-low)/2;
        long long int temp=0;
        temp+=query(segtree,a,b,low,mid,2*i); //does this work with 0-indexed arrays?
        temp+=query(segtree,a,b,mid+1,high,2*i+1);
        return temp;
    }
}
int main(){
    cin>>n>>q;
    vector<long long int> segtree(4*n);
    for(int i=n; i<2*n; i++){
        cin>>segtree[i];
    }
    build(segtree);
    for(int i=0; i<q; i++){
        int a,b,type;
        cin>>type>>a>>b;
        if(type==2){
            cout<<query(segtree,a,b,1,n,1)<<"\n";
        }else{
            set_num(segtree,a,b);
        }
    }

}