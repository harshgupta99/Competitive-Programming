#include<bits/stdc++.h>
using namespace std;
void solve(){
    string B;
    cin >> B;
    string A = "";
    A += B[0];
    A += B[1];
    for(int i = 3; i < B.size(); i+=2){
        A += B[i];
    }
    cout<<A<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}