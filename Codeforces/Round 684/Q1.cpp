//https://codeforces.com/contest/1440/problem/A
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int cost = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            cost += min(c0, c1 + h);
        }
        else{
            cost += min(c1, c0+h);
        }
    }
    cout << cost << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}