#include<bits/stdc++.h>
using namespace std;
long long int solver(int index, vector<long long int> &dp, vector<long long int> &a, int n){
    if(index >= n){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    long long int curr = a[index];
    return dp[index] = curr + solver(index + a[index], dp, a, n);
}
void solve(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long int> dp(n, -1);
    long long int answer = 0LL;
    for(int i = 0; i < n; i++){
        if(dp[i] == -1){
            answer = max(answer, solver(i, dp, a, n));
        }
    }
    cout << answer << "\n";
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