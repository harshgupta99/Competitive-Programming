#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin >> n;
    if(n <= 9LL){
        cout << n << "\n";
        return;
    }
    int answer = 9;
    int sz = 0;
    int cpy_n = n;
    while(cpy_n){
        ++sz;
        cpy_n /= 10;
    }
    int cpy = sz;
    while(cpy - 2 >= 1){
        answer += 9;
        cpy--;
    }
    string cmp = "";
    while(sz){
        sz--;
        cmp += '1';
    }
    string have = to_string(n);
    while(have >= cmp){
        ++answer;
        for(int i = 0; i < (int)cmp.size(); i++){
            cmp[i]++;
        }
    }
    cout << answer << "\n";
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