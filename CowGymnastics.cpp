#include <bits/stdc++.h>
using namespace std;
int check(int l,int k, int j, vector<int> x[], int n){
    for(int i=0; i<l; i++){
        if(find(x[i].begin(), x[i].end(), k)-x[i].begin()>find(x[i].begin(), x[i].end(), j)-x[i].begin()){
            return 0;
        }
    }
    return 1;
}
int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin>>k>>n;

    vector<int> x[k];

    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
        int temp;
        cin>>temp;
        x[i].push_back(temp);
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            count+=check(k,x[0][i],x[0][j], x, n);
        }
    }
    cout<<count;
}