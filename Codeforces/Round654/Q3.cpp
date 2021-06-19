#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int a, b, n, m;
    cin >> a >> b >> n >> m;
    if(a+b < n+m || min(a, b) < m){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}