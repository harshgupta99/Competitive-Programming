#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int answer = 1e18;
    int suff_dist = 0;
    int suff_cnt = 0;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '*'){
            suff_cnt++;
            suff_dist += i;
        }
    }
    int pref_sum = 0;
    int pref_cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '*'){
            continue;
        }
        int prefix = pref_cnt*(i+1) - pref_sum - pref_cnt*(pref_cnt+1)/2;
        int suffix = suff_dist - suff_cnt*(i+1) - (suff_cnt-1)*suff_cnt/2;
        // cout << "At " << i << ": " << prefix << " " << suffix << "\n";
        answer = min(answer, prefix + suffix);
        pref_cnt++;
        pref_sum += (i+1);
        suff_dist -= (i+1);
        suff_cnt--;
    }
    if(answer == 1e18){
        answer = 0LL;
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