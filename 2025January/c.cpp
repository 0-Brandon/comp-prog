#include <bits/stdc++.h>

using namespace std;

int dist(int a,int b, int c, int d){
    return (int)sqrt((b-a)*(b-a)+(c-d)*(c-d));
}
int main(){
    int n, t;
    cin>>n>>t;
    int x, y;
    cin>>x>>y;
    vector<vector<pair<int,int>>> ops(t+1);
    for(int i=0; i<n; i++){
        int s, xi,yi;
        cin>>s>>xi>>yi;
        ops[s].push_back({xi,yi});
    }
    for(int i=0; i<t; i++){
        
    }
}