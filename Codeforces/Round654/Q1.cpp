#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(n&1){
        cout << n/2 + 1 << "\n";
        return;
    }
    cout << n/2 << "\n";
    return;
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}