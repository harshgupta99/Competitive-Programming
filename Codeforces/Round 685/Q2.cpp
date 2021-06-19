//https://codeforces.com/contest/1451/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        char at_start = s[l];
        char at_end = s[r];
        bool ok = false;
        for(int i = 0; i < l; i++){
            ok |= (s[i] == at_start);
        }
        for(int i = r+1; i < n; i++){
            ok |= (s[i] == at_end);
        }
        if(ok){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}