#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool> visited(n+1,false);
    int count = 1;
    int ans = 0;
    while(true){
        int next = (count+count)%n;
        if(visited[next]||next==1){
            ans = count;
            break;
        }
        visited[next] = true;
        count = next;
    }
    cout<<ans;

}