#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
void solve(){
    int n, k;
    cin >> n >> k;
    long long int answer = 1LL;
    for(int i = 0; i < k; i++){
        answer = (answer * n) % MOD;
        if(answer < 0LL){
            answer += MOD;
        }
    }
    cout << answer << "\n";
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