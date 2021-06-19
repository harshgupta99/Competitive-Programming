//https://codeforces.com/contest/1475/problem/B
#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1e6+1, -1);
int helper(long long int n){
    if(n%2021LL == 0LL){
        return 1;
    }
    if(n%2020LL == 0LL){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ok = 0;
    if(n > 2020LL){
        ok += helper(n-2020);
    }
    if(n > 2021LL){
        ok += helper(n - 2021);
    }
    ok = min(1, ok);
    return dp[n] = ok;
}
void solve(){
    long long int n;
    cin >> n;
    bool ok = helper(n);
    if(ok){
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