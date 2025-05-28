#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n;
    cin>>n;
    map<char,int> x;
    for(int i=0; i<n; i++){
        string s, s1;
        cin>>s>>s1;
        for(char j = 'a'; j<='z'; j++){
            x[j]+=max(count(s.begin(), s.end(), j),count(s1.begin(), s1.end(), j));
        }
    }
    for(auto i:x){
        cout<<i.second<<"\n";
    }

}