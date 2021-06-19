#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, x;
    cin >> n >> x;
    vector<long long int> a(n);
    long long int ans = 0;
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        ans += (a[i] + x - 1) / x;
    }
    long long int ans2 = (sum + x - 1) / x;
    cout << min(ans, ans2) << " " << max(ans, ans2) << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}