#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];
    vector<int> dp(n);
    vector<string> dps(n);
    vector<int> trace(n);
    vector<int> dpop(n);
    vector<int> pref(n+1);
    for(int i=0; i<n; i++){
        int idx = i+1;
        bool b = true;
        pref[i+1]=pref[i]+x[i];
        for(int j=0; j<=i; j++){
            if((i-j+1)*(i-j+1)+(j>0?dp[j-1]:0)>dp[i])idx = j,b=true,dp[i] = (i-j+1)*(i-j+1)+(j>0?dp[j-1]:0);
            if(pref[i+1]-pref[j]+(j>0?dp[j-1]:0)>dp[i])idx=j,b=false,dp[i] = pref[i+1]-pref[j]+(j>0?dp[j-1]:0);
        }
        if(b){
        string front = "";
        for(int j=idx; j<=i; j++){
            if(x[j]==0)continue;
            front += to_string(j+1)+" "+to_string(j+1)+"\n";
            dpop[i]++;
        }
        string cur = "";
        int curs = 0;
        for(int j=idx+1; j<=i; j++){
            curs = curs*2+2;
            string ra= to_string(idx+1)+" "+to_string(j+1)+"\n";
            string z = to_string(idx+1)+" "+to_string(j-1+1)+"\n";
            string rep = cur;
            cur += ra+z+rep;
        }
        //at the last index, we just set range
        cur +=to_string(idx+1)+" "+to_string(i+1)+"\n";
        curs++;
        dpop[i]+=curs;
        dps[i] = front+cur;
        }
        trace[i]=idx-1;
        dpop[i]+=(idx>0?dpop[idx-1]:0);
    }
    cout<<dp.back()<<" "<<dpop.back()<<"\n";
    int i = n-1;
    while(i>=0){
        cout<<dps[i];
        i=trace[i];
    }
}