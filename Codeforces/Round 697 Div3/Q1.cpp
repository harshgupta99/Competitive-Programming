//https://codeforces.com/contest/1475/problem/0
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin >> n;
    while(n%2LL == 0){
        n /= 2;
    }
    if(n&1LL && n != 1LL){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}