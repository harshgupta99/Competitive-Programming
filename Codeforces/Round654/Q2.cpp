#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, r;
    cin >> n >> r;
    if(r < n){
        cout << r*(r+1)/2 << "\n";
        return;
    }
    long long int answer = 0;
    answer += n*(n-1)/2 + 1;
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