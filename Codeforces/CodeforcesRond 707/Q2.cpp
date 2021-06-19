#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> cnt(n+1, 0);
    for(int i = 0; i < n; i++){
        int lower = max(-1, i-a[i]);
        int upper = i;
        if(lower == upper){
            continue;
        }
        cnt[upper+1]--;
        cnt[lower+1]++;
    }
    vector<int> answer(n, 0);
    int c = 0;
    for(int i = 0; i < n; i++){
        c += cnt[i];
        if(c > 0){
            answer[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] <<  " ";
    }
    cout << "\n";
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