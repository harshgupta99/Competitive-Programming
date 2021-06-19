#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin >> n;
    long long int prod = 1LL;
    vector<long long int> numbers;
    for(long long int num = 1; num <= n-1; num++){
        if(__gcd(num, n) == 1){
            prod *= num;
            prod %= n;
            numbers.push_back(num);
        }
    }
    if(prod == 1LL){
        cout << numbers.size() << "\n";
        for(auto x : numbers){
            cout << x << " " ;
        }
        cout << "\n";
        return;
    }
    cout << numbers.size()-1 << "\n";
    for(auto x : numbers){
        if(x == prod){
            continue;
        }
        cout << x << " ";
    }
    cout << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    //cin >> test_cases;
    for(int tt = 1; tt <= test_cases; tt++){
        solve();
    }
}