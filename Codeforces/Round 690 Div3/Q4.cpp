//https://codeforces.com/contest/1462/problem/D
#include<bits/stdc++.h>
using namespace std;
vector<int> factors(int n){
    vector<int> a;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            a.push_back(i);
            if(n/i != i){
                a.push_back(n/i);
            }
        }
    }
    return a;
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    vector<int> fact = factors(sum);
    int mx = *max_element(a.begin(), a.end());
    int answer = n-1;
    sort(fact.begin(), fact.end());
    for(int i = 0; i < (int)fact.size(); i++){
        if(fact[i] < mx){
            continue;
        }
        int s = 0;
        int curr = 0;
        for(int j = 0; j < n; j++){
            s += a[j];
            ++curr;
            if(s == fact[i]){
                curr--;
                s = 0;
            }
            else if(s > fact[i]){
                curr = 1e9;
                break;
            }
        }
        if(s != 0){
            curr = 1e9;
        }
        answer = min(answer, curr);
    }
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