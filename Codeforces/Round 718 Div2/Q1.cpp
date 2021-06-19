#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin >> n;
    int moves = 0;
    while(n >= 2050*1LL){
        long long int mul = 1LL;
        while(n >= 2050*mul){
            mul *= 10;
        }
        if(2050*mul > n){
            mul /= 10;
        }
        moves++;
        n -= 2050*mul;
    }
    if(n == 0LL){
        cout << moves << endl;
    }
    else{
        cout << "-1\n";
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}