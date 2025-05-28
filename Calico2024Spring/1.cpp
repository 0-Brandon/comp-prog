#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string cc(const string& input) {
    string result; 
        if (input.substr(0, 6) == "calico") {
            result = input;
            transform(result.begin(), result.begin() + 6, result.begin(), ::toupper);
        } else if (input.substr(0, 5) == "alico") {
            result = "CALICO" + input.substr(5);
        } else if (input.substr(0, 4) == "lico") {
            result = "CALICO" + input.substr(4);
        } else if (input.substr(0, 3) == "ico") {
            result = "CALICO" + input.substr(3);
        } else if (input.substr(0, 2) == "co") {
            result = "CALICO" + input.substr(2);
        } else if (input[0] == 'o') {
            result = "CALICO" + input.substr(1);
        } else {
            
            result = input;
        }
    return result;
}

void solve(){
    string s;
    cin>>s;
    cout<<cc(s)<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}