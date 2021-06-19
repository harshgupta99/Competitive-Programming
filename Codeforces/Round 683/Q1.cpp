#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    cout << n << "\n";
    for(int i = 0; i < n; i++){
        cout << i+1 << " ";
    }
    cout << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}