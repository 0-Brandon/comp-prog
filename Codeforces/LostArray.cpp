#include <bits/stdc++.h>

using namespace std;


int main(){
    int n, k;cin>>n>>k;
    if(n%2==1&&k%2==0){cout<<"-1\n";return 0;}
    if(!(k%2==1&&n%2==0&&2*k>n)){
    int ans = 0;
    for(int i=1; i+k-1<=n; i+=k){
        cout<<"? ";
        for(int j=i, c=0; c<k; j++,c++){
            cout<<j<<" ";
        }
        int t;
        cin>>t;ans^=t;
    }
    if(n%k!=0){
    int d = n%k/2;
    cout<<"? ";
    for(int j=n+1-d-k,c=0;c<k; j++,c++){
        cout<<j<<" ";
    }
    int a;
    cin>>a;

    cout<<"? ";
    for(int j=n+1-2*d-(k-d), c=0; c<k-d; j++,c++){
        cout<<j<<" ";
    }
    for(int j=n+1-d, c=0;c<d; c++,j++){
        cout<<j<<" ";
    }
    int b;cin>>b;
    ans^=a^b;
    }
    cout<<"! "<<ans<<"\n";
    }
    else{
    }
}