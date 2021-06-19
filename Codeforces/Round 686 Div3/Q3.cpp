//https://codeforces.com/contest/1454/problem/D
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin >> n;
    long long int cpy_n = n;
    map<long long int, int> fact;
    for(long long int i = 2; i*i <= cpy_n; i++){
        while(cpy_n%i == 0){
            fact[i]++;
            cpy_n /= i;
        }
    }
    if(cpy_n > 1){
        fact[cpy_n]++;
    }
    int mx = 0;
    long long int which = -1;
    for(auto x : fact){
        if(x.second > mx){
            mx = x.second;
            which = x.first;
        }
    }
    assert(which != -1);
    vector<long long int> answer(mx, which);
    fact[which] -= mx;
    for(auto x : fact){
        int cnt = x.second;
        while(cnt){
            --cnt;
            answer.back() *= x.first;
        }
    }
    cout << (int)answer.size() << "\n";
    for(int i = 0; i < (int)answer.size(); i++){
        cout << answer[i] << " ";
    }
    puts("");
    return; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}