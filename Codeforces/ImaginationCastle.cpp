#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;cin>>n>>m>>k;
    vector<vector<int>> x(n);
    for(int i=0; i<k; i++){
        int a, b;cin>>a>>b;a--,b--;
        x[a].push_back(b);
    }
    set<int> s;
    for(int i=0; i<n; i++){
        s.insert(i);
    }
    for(int i=n-1; i>=0; i--){
        if(s.empty())break;
        int c = *s.rbegin();
        bool lose = true;
        for(auto& y:x[i]){
            if(y>c){
                lose = false;
            }
        }
        if(lose){
            s.erase(c);
            if(i==0&&c==0){
                cout<<"Bhinneka\n";return 0;
            }
        }
        for(auto& y:x[i]){
            s.erase(y);
        }
    }
    cout<<"Chaneka\n";
}