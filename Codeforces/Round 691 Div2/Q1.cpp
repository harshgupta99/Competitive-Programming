//https://codeforces.com/contest/1465/problem/B
#include<bits/stdc++.h>
using namespace std;
bool is_okay(string s){
    long long int num = 0LL;
    long long int mul = 1LL;
    for(int i = s.size()-1; i >= 0; i--){
        num += (long long int)(s[i] - '0') * mul;
        mul *= 10;
    }
    for(int i = 0; i < (int)s.size(); i++){
        if((s[i]-'0') == 0){
            continue;
        }
        if(num%(s[i]-'0')){
            return false;
        }
    }
    return true;
}
void solve(){
    long long int n;
    cin >> n;
    string s = to_string(n);
    for(int i = s.size()-1; i >= 0; i--){
        char d = s[i];
        for(int digit = (s[i]-'0'); digit <= 9; digit++, d++){
                string tmp = s;
                tmp[i] = d;
                if(is_okay(tmp)){
                cout << tmp << "\n";
                return;
            }
        }
        
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}