//https://codeforces.com/contest/1451/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++){
        ++cnt[a[i]-'a'];
    }
    for(int i = 0; i < n; i++){
        --cnt[b[i]-'a'];
    }
    if(cnt[25] > 0 || cnt[0] < 0){
        puts("No");
        return;
    }
    int extra = 0;
    for(int i = 0; i < 26; i++){
        if(abs(cnt[i]) % k != 0){
            puts("No");
            return;
        }
        extra += cnt[i]/k;
        if(extra < 0){
            puts("No");
            return;
        }
    }
    if(extra != 0){
        puts("No");
        return;
    }
    puts("Yes");
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
