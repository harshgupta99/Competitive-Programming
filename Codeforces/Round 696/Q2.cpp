//https://codeforces.com/contest/1474/problem/B
#include<bits/stdc++.h>
using namespace std;
vector<bool> seive(1e7, true);
vector<int> primes;
void pre(){
    seive[1] = false;
    for(long long int i = 2LL; i*i < 1e7; i++){
        if(seive[i]){
            for(long long int j = i*i; j < 1e7; j += i){
                seive[j] = false;
            }
        }
    }
    for(int i = 2; i < 1e7; i++){
        if(seive[i]){
            primes.push_back(i);
        }
    }
    //cout << primes.size() << "\n";
    return;
}
void solve(){
    int d;
    cin >> d;
    long long int first = (long long int)primes[(lower_bound(primes.begin(), primes.end(), 1LL + d) - primes.begin())];
    long long int second = (long long int)primes[(lower_bound(primes.begin(), primes.end(), first + d) - primes.begin())];
    long long int answer = 1LL * first * second;
    cout << answer << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// 1 2 3 5 7 11 13 17 19 23 29
// 1 5 11 55