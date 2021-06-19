#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int a, b;
    cin >> a >> b;
    // side of square should be
    ll side = max(2*min(a, b), max(a, b));
    cout<<side*side<<"\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}