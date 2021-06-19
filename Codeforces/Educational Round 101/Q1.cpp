#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int cnt = 0;
    int n = (int)s.size();
    if(s[0] == ')'){
        puts("NO");
        return;
    }
    if(s[n-1] == '('){
        puts("NO");
        return;
    }
    if(n&1){
        puts("NO");
        return;
    }
    puts("YES");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}