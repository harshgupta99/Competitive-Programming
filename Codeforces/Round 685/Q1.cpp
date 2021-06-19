//https://codeforces.com/contest/1451/problem/A
#include<bits/stdc++.h>
using namespace std;
long long int solver(long long int n){
   // cout << n << "\n";
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(n&1){
        return 1 + solver(n-1);
    }
    return 1 + solver(min(n/2, 2LL));
}
void solve(){
    long long int n;
    cin >> n;
    long long int answer = solver(n);
    cout << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}