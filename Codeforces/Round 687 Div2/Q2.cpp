//https://codeforces.com/contest/1457/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int answer = 1e9;
    for(int i = 1; i <= 100; i++){
        int this_color = 0;
        for(int j = 0; j < n;){
            if(a[j] == i){
                j++;
                continue;
            }
            this_color++;
            j += k;
        }
        answer = min(answer, this_color);
    }
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