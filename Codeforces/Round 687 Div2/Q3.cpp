//https://codeforces.com/contest/1457/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, p, k;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    // make groups of i+p + x*k
    int x, y;
    cin >> x >> y;
    p--;
    long long int answer = 1e18;
    vector<int> pref(n, 0);
    for(int i = n-1; i >= 0; i--){
        if(i+k < n){
            pref[i] = pref[i+k] + (s[i] == '0');
        }
        else{
            pref[i] = (s[i] == '0');
        }
    }
    for(int i = 0; i+p < n; i++){
        answer = min(answer, (long long int)(y * i) + (long long int)pref[i+p]*x);
    }
    cout << answer << "\n";
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