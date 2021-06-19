//https://codeforces.com/gym/102942/problem/D
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a, b;
    cin >> a >> b;
    for(int bit = 0; bit < 30; bit++){
        if(a&(1 << bit) && b&(1 << bit)){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// 0110
// 1010
// 110