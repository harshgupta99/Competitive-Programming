//https://codeforces.com/contest/1474/problem/0
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a = "";
    // 210210210
    int prev = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            a += '1';
            prev = (1 + (s[0] - '0'));
        }
        else{
            int c = s[i] - '0';
            if(1 + c == prev){
                a += '0';
                prev = c;
            }
            else{
                a += '1';
                prev = 1 + c;
            }
        }
    }
    cout << a << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}