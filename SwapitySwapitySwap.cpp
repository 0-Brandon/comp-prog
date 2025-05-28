#include <bits/stdc++.h>

using namespace std;
int findx(int i, vector<int>& p){
    int x=0;
    while(p[i]!=i){
        x++;
        i=p[i];
    }
    return x;
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> cows(n);
    vector<int> p(n);
    iota(cows.begin(),cows.end(),0);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--, b;
        reverse(cows.begin()+a, cows.begin()+b);
    }
    for(int i=0; i<n; i++){
        p[cows[i]]=i;
    }
    for(int i=0; i<n; i++){
        int l = i;
        int lo = findx(i,p);
        lo=k%lo;
        for(int j=0; j<lo; j++){
            l = p[l];
        }
        cout<<l+1<<"\n";
    }

}