#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    vector<int> occ(k,-1);
    for(int i=0; i<n; i++){
        cin>>x[i];x[i]--;
        if(occ[x[i]]==-1)occ[x[i]]=i;
    }
    vector<vector<bool>> can(k,vector<bool>(k,0));
    for(int i=0; i<k; i++){
        string s;
        cin>>s;
        for(int j=0; j<k; j++){
            can[i][j]=s[j]-'0';
        }
    }
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    for(int time=0; time<=k; time++){
        int end = (time&1)?(-1):(n);
        int start =(time&1)?(n-1):(0);
        int c = (start<end)?(1):(-1);
        vector<int> close(k,-1);
        for(int i=start; i!=end; i+=c){
            for(int j=0; j<k; j++){
                if(can[j][x[i]]&&close[j]!=-1)dist[i] = min(dist[i],dist[close[j]]+abs(i-close[j]));
            }
            if(close[x[i]]==-1||(dist[i]<dist[close[x[i]]]))close[x[i]]=i;
        }
    }
    if(dist[n-1]==INT_MAX)dist[n-1]=-1;
    cout<<dist[n-1];
}