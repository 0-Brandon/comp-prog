#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    set<int> ans;
    auto f = [&](int i, int j){
        string st = s.substr(i,j);
        int ans = 0;
        int b = 1;
        for(int i=st.size()-1; i>=0; i--){
            ans+=(st[i]-'0')*b;
            b*=10;
        }
        return ans;
    };
    auto work = [&](int k){
        int kk=k;
        //check if it starts length k
        bool b = false;
        set<int> tmp;
        int last = f(0,k)-1;
        int i=0;
        for(; i+k<=n; i+=k){
            int num = f(i,k);
            //cout<<last<<" "<<num<<"\n";
            if(s.substr(i,k)==string(k,'9'))k++,i--;
            if(num==last+1){
                last=num;
                continue;
            }
            else if(b){
                return;
            }
            else if(num==last+2){
                tmp.insert(last+1);
                b=true;
                last = num;
            }else if(i+k+1<=n&&f(i,k+1)==last+2){
                tmp.insert(last+1);
                b=true;
                last = num;
                k++,i--;
            }
            else{
                return;
            }
        }
        if(i==n&&!b){
            if(last+1<=99999)ans.insert(last+1);
            if(f(0,kk)-1>=1)ans.insert(f(0,kk)-1);
        }
        for(auto& i:tmp)ans.insert(i);
    };
    for(int i=1; i<=5; i++){
        work(i);
    }
    cout<<ans.size()<<"\n";
    for(auto& i:ans)cout<<i<<" ";
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}