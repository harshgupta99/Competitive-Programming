#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int answer = 0;
    int best = 0, curr = 0;
    for(int i = 0; i < n; i++){
        curr += a[i];
        best = max(best, curr);
    }
    answer += best;
    best = 0;
    curr = 0;
    for(int i = 0; i < m; i++){
        curr += b[i];
        best = max(best, curr);
    }
    answer += best;
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