#include <bits/stdc++.h>

using namespace std;

//Arival time, seniority, eating time
int main(){
    freopen("convention2.out","w",stdout);
    freopen("convention2.in","r",stdin);
    int n;
    cin>>n;
    vector<int> ans(n);
    vector<vector<int>> cows(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        cows[i]={a,i,b};
    }
    auto comp = [&](vector<int>& a, vector<int>& b){return a[0]<b[0]||(a[0]==b[0])&&(a[1]>b[1]);};
    sort(cows.begin(),cows.end(),comp);
    auto comp1 = [&] (vector<int>& a, vector<int>& b){return a[1]>b[1];};
    priority_queue<vector<int>,vector<vector<int>>, decltype(comp1)> x(comp1);
    x.push(cows[0]);
    int i=1;
    int counter = cows[0][0];
    while(!x.empty()){
        vector<int> cur = x.top();
        x.pop();
        ans[cur[1]]=counter-cur[0];
        counter+=cur[2];
        while(i<n&&cows[i][0]<=counter){
            x.push(cows[i++]);
        }
        if(i<n&&x.empty()){
            counter = cows[i][0];
            x.push(cows[i++]);
        }
    }
    cout<<*max_element(ans.begin(),ans.end());
}