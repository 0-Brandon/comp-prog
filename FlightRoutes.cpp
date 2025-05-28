#include <bits/stdc++.h>

using namespace std;
const int sss = 750;
int main(){
    int n;
    cin>>n;
    string pre = "";
    vector<bitset<sss>> x;
    for(int i=0; i<n-1; i++){
        string s;
        cin>>s;
        string cur = pre+s;
        x.emplace_back(cur);
        pre+="0";
    }
    int ans = 0;
    for(int i=0; i<n-1; i++){
        bitset<sss> cur;
        for(int j=n-i-1; j>=0; j--){
            if(cur[j]!=x[i][j]){
                ans++;
                if(j!=0)cur^=x[n-1-j];
            }
        }
    }
    cout<<ans<<"\n";    
}