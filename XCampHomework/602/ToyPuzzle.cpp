#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> x(n);
    vector<int> dir(n);
    for(int i=0; i<n; i++){
        cin>>dir[i]>>x[i];
        if(dir[i]==0)dir[i]=1;
        else dir[i]=-1;
    }
    int id = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        if(a==1)a=1;
        else a = -1;
        id = id+a*dir[id]*b;
        id=(id+n)%n;
    }
    cout<<x[id]<<"\n";
}