#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++){
        if(cnt[s[i] - 'A'] == 0){
            cnt[s[i] - 'A']++;
        }
        else if(i && s[i] == s[i-1]){
            ;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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