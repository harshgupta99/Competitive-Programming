#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    long long int XOR = 0LL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        XOR ^= a[i];
    }
    long long int pref_xor = 0LL;
    if(XOR == 0LL){
        cout << "YES\n";
        return;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        pref_xor ^= a[i];
        if(pref_xor == XOR){
            ++cnt;
            pref_xor = 0;
        }
    }
    if(pref_xor == 0 && cnt > 1){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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