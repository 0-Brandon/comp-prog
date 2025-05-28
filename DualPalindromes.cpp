/*
NAME: bwang741
LANG: C++17
TASK: dualpal
*/


#include <bits/stdc++.h>

using namespace std;
bool base(int x, int base){
    int a=x, q = 1, r=1;
    string ans = "";
    while(q!=0){
        q=a/base;
        r=a%base;
        a=q;
        ans.insert(0,to_string(r));
    }
    string temp = ans;
    reverse(ans.begin(), ans.end());
    return temp == ans;

}
int main(){
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s;
    cin>>n>>s;
    int count = 0;
    int curr = 0;
    while(count<n){
        s++;
        for(int i=2; i<=10; i++){
            if(base(s,i)){
                curr++;
            }
            if(curr==2){
                count++;
                cout<<s<<"\n";
                break;
            }
        }
        curr=0;
    }
}