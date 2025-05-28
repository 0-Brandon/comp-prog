#include <bits/stdc++.h>

using namespace std;

long long dist(int i, int j, int x, int  y){
    return 1LL*(y-j)*(y-j)+1LL*(x-i)*(x-i);
}
int main(){
    int n, g;
    cin>>g>>n;
    vector<tuple<int,int,int>> gloc;
    for(int i=0; i<g; i++){
        int a, b, c;
        cin>>a>>b>>c;
        gloc.emplace_back(c,a,b);
    }
    sort(gloc.begin(),gloc.end());
    vector<tuple<int,int,int>> cow;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        cow.emplace_back(c,a,b);
    }
    sort(cow.begin(),cow.end());
    int count = 0;
    int idx = 0;
    int glidx = 0, ghidx=1;
    while(idx<cow.size()){
        auto[k,i,j]=cow[idx];
        while(k>get<0>(gloc[ghidx])){
            if(ghidx<gloc.size()-1)ghidx++;
            if(ghidx==gloc.size()-1)break;
        }
        glidx = ghidx-1;
        if(k>get<0>(gloc[ghidx]))glidx=ghidx;
        auto[low1, low2, low3] = gloc[glidx];
        auto[high1, high2, high3] = gloc[(k>get<0>(gloc[0])?ghidx:0)];
        if(!(dist(i,j,low2,low3)<=1LL*(low1-k)*(low1-k)&&dist(i,j,high2,high3)<=1LL*(high1-k)*(high1-k))){
            count++;
        }
        idx++;
    }
    cout<<count;
}