#include <bits/stdc++.h>

using namespace std;
int merge(int l, int mid, int r, vector<int>& x){
    int count = 0;
    int i=l,j=mid;
    vector<int> aux(x.size());
    int t = 0;
    while(i<mid&&j<r){
        if(x[i]<=x[j]){
            aux[t++]=x[i++];
        }else{
            aux[t++]=x[j++];
            count += mid-i;
        }
    }
    while(i<l){
        aux[t++]=x[i++];
    }
    while(j<r){
        aux[t++]=x[j++];
    }
    t=0;
    for(int k=l; k<r; k++){
        x[k]=aux[t++];
    }
    return count; 
}
int mergesort(int l , int r, vector<int> & x){
    int count = 0;
    int mid = (l+r)/2;
    if(l<r){
        count+=mergesort(l,mid,x);
        count+=mergesort(mid+1,r,x);
        count+=merge(l,mid,r,x);
    }
    return count;
}

int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    cout<<mergesort(0,n,x);
}