#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool ok = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int sq = sqrt(a[i]);
        if(sq*sq != a[i] && !ok){
            cout << "YES\n";
            ok = true;
        }
    }
    if(!ok){
        cout << "NO\n";
        return;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases;
    cin >> test_cases;
    for(int tt = 1; tt <= test_cases; tt++){
        solve();
    }
}