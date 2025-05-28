#include <bits/stdc++.h>

using namespace std;
//Work In Progress
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    //dp[i][j][k] is min dist 
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1)));
    for(int i=0; i<n; i++){ //current room
        for(int j=0; j<n; j++){ //first door 
            for(int d=0; d<k;d++){ //number of doors already placed
            dp[i][j][d+1]=dp[i][j][d]; // start with if there was no door
            int cost=0; // distance traveled by cows from here till beginning
            for(int s=0; s!=j; s=(s+1)%n){
                 cost+=s*x[s];
            }
            for(int last=i-1; last>=0; last--){ //last door placed
                
            }
            } 
        }
    }
}