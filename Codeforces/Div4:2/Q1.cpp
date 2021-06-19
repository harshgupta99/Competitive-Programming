//https://codeforces.com/gym/102942/problem/0
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int curr = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            ++curr;
            if(curr == 4){
                curr = 0;
            }
        }
        else{
            --curr;
            if(curr == -1){
                curr = 3;
            }
        }
    }
    if(curr == 0){
        puts("N");
    }
    else if(curr == 1){
        puts("E");
    }
    else if(curr == 2){
        puts("S");
    }
    else{
        puts("W");
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