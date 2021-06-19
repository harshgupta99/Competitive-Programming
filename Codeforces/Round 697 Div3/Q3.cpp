//https://codeforces.com/contest/1475/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int a, b, k;
    cin >> a >> b >> k;
    vector<pair<int, int> > A(k);
    vector<int> freq_boys(a+1, 0), freq_girls(b+1, 0);
    for(int i = 0; i < k; i++){
        cin >> A[i].first;
        freq_boys[A[i].first]++;
    }
    for(int i = 0; i < k; i++){
        cin >> A[i].second;
        freq_girls[A[i].second]++;
    }
    long long int answer = 0LL;
    for(int i = 0; i < k; i++){
        // remove this pair
        long long int possible = 1LL * max(0LL, k - freq_girls[A[i].second] - freq_boys[A[i].first] + 1);
        answer += possible;
    }
    cout << answer/2 << "\n";
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