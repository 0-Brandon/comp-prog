#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<int> x;
    int s;
    cin>>s;
    int n=1;
    for(int i=0; i<s; i++){
        char a, d;
        int num;
        cin>>a>>d;
        if(a=='D'){
            cin>>num;
            for(int i=0; i<num; i++){
                if(d=='L'){
                    x.pop_front();
                }
                else{
                    x.pop_back();
                }
            }
        }
        else{
            if(d=='L'){
                x.push_front(n);
            }
            else{
                x.push_back(n);
            }
            n++;
        }
    }
    while(!x.empty()){
        cout<<x.front()<<"\n";
        x.pop_front();
    }
}