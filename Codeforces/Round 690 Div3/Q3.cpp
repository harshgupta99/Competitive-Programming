//https://codeforces.com/contest/1462/problem/C
#include<bits/stdc++.h>
using namespace std;
string answer;
void helper(int n, string k){
    if(n == 0){
        sort(k.begin(), k.end());
        if(answer == "-1" || answer.size() > k.size()){
            answer = k;
        }
        else if(answer.size() < k.size()){
            ;
        }
        else{
            answer = min(answer, k);
        }
        return;
    }
    char a = '1';
    for(int i = 1; i <= 9; i++, a++){
        if(i > n){
            break;
        }
        if(find(k.begin(), k.end(), a) != k.end()){
            continue;
        }
        helper(n-i, k+a);
    }
    return;
}
void solve(){
    answer = "-1";
    int n;
    cin >> n;
    helper(n, "");
    cout << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}