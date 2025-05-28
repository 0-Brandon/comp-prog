#include <bits/stdc++.h>

using namespace std;
/*
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<int> lastb(n+1,-1), lasts(n+1,-1), laste(n+1,-1), lasti(n+1,-1);
    for(int i=1; i<=n; i++){
        if(i>0){
        lastb[i]=lastb[i-1];
        lasts[i]=lasts[i-1];
        laste[i]=laste[i-1];
        lasti[i]=lasti[i-1];
        if(s[i-1]=='b')lastb[i]=i-1;
        if(s[i-1]=='e')laste[i]=i-1;
        if(s[i-1]=='s')lasts[i]=i-1;
        if(s[i-1]=='i')lasti[i]=i-1;
        }
    }
    long long ans = 0;
    long long int rb=0;
    bool b=false, e1=false, s1=false, s2=false, i1=false, e2=false;
    for(int i=0; i<n; i++){
        if(s[i]=='b')b=true;
        if(b&&s[i]=='e')e1=true;
        if(s1&&s[i]=='s')s2=true;
        if(e1&&s[i]=='s')s1=true;
        if(s2&&s[i]=='i')i1=true;
        if(i1&&s[i]=='e')e2=true;
        if(e2){
            if(lasti[i]<0)rb=-1;
            else if(lasts[lasti[i]]<0)rb=-1;
            else if(lasts[lasts[lasti[i]]]<0)rb=-1;
            else if(laste[lasts[lasts[lasti[i]]]]<0)rb=-1;
            else if(lastb[laste[lasts[lasts[lasti[i]]]]]<0)rb=-1;
            else rb = lastb[laste[lasts[lasts[lasti[i]]]]];
            cout<<lastb[laste[lasts[lasts[lasti[i]]]]]<<"\n";
            cout<<laste[lasts[lasts[lasti[i]]]]<<"\n";
            cout<<lasts[lasts[lasti[i]]]<<"\n";
            cout<<lasts[lasti[i]]<<"\n";
            cout<<lasti[i]<<"\n";
            cout<<i<<"\n";
            ans+=1LL*(rb+1)*(s.size()-i);
            b=false,e1=false,s1=false,s2=false,i1=false,e2=false;
        }
    }
    cout<<ans;
}
*/
int main(){
    string s;
    cin>>s;
    int n = s.size();
    if(n<6000){
    long long ans = 0;
        vector<int> lastb(n+1,-1), lasts(n+1,-1), laste(n+1,-1), lasti(n+1,-1);
    for(int i=1; i<=n; i++){
        if(i>0){
            lastb[i]=lastb[i-1];
            lasts[i]=lasts[i-1];
            laste[i]=laste[i-1];
            lasti[i]=lasti[i-1];
            if(s[i-1]=='b')lastb[i]=i-1;
            if(s[i-1]=='e')laste[i]=i-1;
            if(s[i-1]=='s')lasts[i]=i-1;
            if(s[i-1]=='i')lasti[i]=i-1;
        }
    }
    int rb=-1;
    int b=0, be=0, bes=0, bess=0, bessi=0 ,bessie=0;
    for(int i=0; i<n; i++){
        if(s[i]=='b'){
            b++;
        }
        if(s[i]=='e'){
            bessie=bessi;
            if(bessie>0){
                if(lasti[i]<0)rb=-1;
            else if(lasts[lasti[i]]<0)rb=-1;
            else if(lasts[lasts[lasti[i]]]<0)rb=-1;
            else if(laste[lasts[lasts[lasti[i]]]]<0)rb=-1;
            else if(lastb[laste[lasts[lasts[lasti[i]]]]]<0)rb=-1;
             else rb = lastb[laste[lasts[lasts[lasti[i]]]]];
                ans+=(rb+1)*1LL*(s.size()-i);
                b=0,be=0,bes=0,bess=0,bessi=0,bessie=0;
                rb=-1;
            }
            be=b;
        }
        if(s[i]=='s'){
            bess=bes;
            bes=be;
        }
        if(s[i]=='i')bessi=bess;
    }
    cout<<ans;
}else{
    
    long long ans = 0;
        vector<int> lastb(n+1,-1), lasts(n+1,-1), laste(n+1,-1), lasti(n+1,-1);
    for(int i=1; i<=n; i++){
        if(i>0){
        lastb[i]=lastb[i-1];
        lasts[i]=lasts[i-1];
        laste[i]=laste[i-1];
        lasti[i]=lasti[i-1];
        if(s[i-1]=='b')lastb[i]=i-1;
        if(s[i-1]=='e')laste[i]=i-1;
        if(s[i-1]=='s')lasts[i]=i-1;
        if(s[i-1]=='i')lasti[i]=i-1;
        }
    }
    int rb=-1;
    int b=0, be=0, bes=0, bess=0, bessi=0 ,bessie=0;
    int ov=0;
    for(int i=0; i<n; i++){
        if(s[i]=='b'){
            b++;
            if(b>1)ov++;
        }
        if(s[i]=='e'){
            bessie=bessi;
            if(bessie>0){
                if(lasti[i]<0)rb=-1;
            else if(lasts[lasti[i]]<0)rb=-1;
            else if(lasts[lasts[lasti[i]]]<0)rb=-1;
            else if(laste[lasts[lasts[lasti[i]]]]<0)rb=-1;
            else if(lastb[laste[lasts[lasts[lasti[i]]]]]<0)rb=-1;
             else rb = lastb[laste[lasts[lasts[lasti[i]]]]];
                ans+=(rb+1)*1LL*(s.size()-i);
                b=0,be=0,bes=0,bess=0,bessi=0,bessie=0;
                rb=-1;
            }
            be=b;
        }
        if(s[i]=='s'){
            bess=bes;
            bes=be;
        }
        if(s[i]=='i')bessi=bess;
    }
    cout<<ans-ov;
}
}

