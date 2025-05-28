#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cin>>m;
    vector<string> scales(m);
    vector<int> ord(m);
    string x;
    for(int i=0; i<m; i++){
        cin>>scales[i];
    }
    for(int i=0; i<m; i++){
        cin>>ord[i];
        ord[i]--;
    }
    cin>>x;
    int count = 0;
    int idx=0;
    for(int i=0; i<=4*m-4; i+=4){
        for(int k=i; k<=i+3; k++){
            if(scales[ord[idx]].find(x[k])==string::npos)count++;
        }
        idx++;
    }
    cout<<count;
}