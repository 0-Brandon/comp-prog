#include <bits/stdc++.h>

using namespace std;
/*
int main(){
    int t;
    cin>>t;
    while(t--){
        bool ok = true;
        int n, m;
        cin>>n>>m;
        vector<vector<int>> past(m,vector<int>(n));
        vector<int> pastout(m);
        map<string,int> ans;
        for(int i=0; i<m; i++){
            string temp;
            cin>>temp;
            for(int j=0; j<n; j++){
                past[i][j]=temp[j];
            }
            cin>>pastout[i];
            vector<int> numdiffer(i+1);
            for(int j=0; j<i; j++){
                int currdif=0;
                for(int k=0; k<n; k++){
                    if(past[i][k]!=past[j][k]){
                        currdif++;
                    }
                }
                numdiffer[j]=currdif;
            }
        }
            for(int j=0; j<i; j++){
                if(numdiffer[j]>=n&&pastout[i]==pastout[j]){
                    ok=false;
                    break;
                }
                if(numdiffer[j]==0&&pastout[j]!=pastout[i]){
                    ok=false;
                    break;
                }
            }
        }
        cout<<(ok?"OK":"LIE")<<'\n';
    }
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        bool ok = true;
        int n, m;
        cin>>n>>m;
        vector<bitset<101>> past;
        vector<int> pastout;
        map<string,int> ans;
        for(int i=0; i<m; i++){
            string temp;
            cin>>temp;
            bitset<101> b(temp);
            int out;
            cin>>out;
            if(ans.count(temp)&&ans[temp]!=out){
                ok=false;
                break;
            }
            past.push_back(b);
            pastout.push_back(out);
            for(int j=0; j<i; j++){
                ans[(past[i]|past[j]).to_string().substr(101-n,n)]=pastout[j]|pastout[i];
            }
            ans[temp]=out;
        }
        cout<<(ok?"OK":"LIE")<<'\n';
    }
}
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        map<string,int> x;
        int n, m;
        cin>>n>>m;
        bool ok = true;
        for(int i=0; i<m; i++){
            string temp;
            cin>>temp;
            int out;
            cin>>out;
            if(out!=0&&out!=1){
                ok=false;
            }
            if(x.count(temp)&&x[temp]!=out) {
                ok=false;
            }
            x[temp]=out;
        }
        if(!ok){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x["01"]==1&&x["01"]==x["10"]&&x["11"]!=x["01"]){
            cout<<"LIE"<<"\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["01"]==x["11"]&&x["10"]!=x["11"]&&x["10"]!=x["00"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["11"]&&x["10"]!=x["11"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["11"]&&x["01"]!=x["11"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["11"]&&x["01"]!=x["11"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["01"]&&x["01"]==x["10"]&&x["01"]!=x["11"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["01"]&&x["01"]==x["11"]&&x["11"]!=x["01"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["01"]&&x["10"]==x["11"]&&x["11"]!=x["10"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("11")&&x.count("00")&&x["00"]==x["01"]&&x["10"]==x["11"]&&x["11"]!=x["10"]){
            cout<<"LIE\n";
            continue;
        }
        if(x.count("01")&&x.count("10")&&x.count("00")&&x["01"]==0&&x["01"]==x["10"]&&x["00"]!=x["01"]){
            cout<<"LIE"<<"\n";
            continue;
        }
        cout<<"OK\n";
    }
}