//https://codeforces.com/contest/1457/problem/0
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, m, r, c;
    cin >> n >> m >> r >> c;
    long long int answer = abs(1 - r) + abs(1 - c);
    answer = max(answer, abs(n-r) + abs(m-c));
    answer = max(answer, abs(1 - r) + abs(m - c));
    answer = max(answer, abs(n-r) + abs(1-c));
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