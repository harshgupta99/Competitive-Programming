//https://codeforces.com/contest/1462/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.substr(0, 4) == "2020"){
        puts("YES");
        return;
    }
    if(s.substr(n-4) == "2020"){
        puts("YES");
        return;
    }
    if(s[0] == '2' && s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0'){
        puts("YES");
        return;
    }
    if(s[0] == '2' && s[1] == '0' && s[n-2] == '2' && s[n-1] == '0'){
        puts("YES");
        return;
    }
    if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[n-1] == '0'){
        puts("YES");
        return;
    }
    puts("NO");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}