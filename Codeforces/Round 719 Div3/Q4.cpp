#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int answer = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        answer += mp[(a[i] - (i+1))];
        mp[a[i] - (i+1)]++;
    }
    cout << answer << "\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cases;
    cin >> test_cases;
    for(int tt = 1; tt <= test_cases; tt++){
        solve();
    }
}