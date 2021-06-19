#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll a, b;
    // 3 3
    cin >> a >> b;
    if(a == 0 || b == 0){
        cout<<"0\n";
        return;
    }
    if(a < 2ll && b < 2ll){
        cout<<"0\n";
        return;
    }
    if(a == b){
        ll ans = a/2;
        ll rem = a%2;
        if(rem){
            ans++;
        }
        cout<<ans<<"\n";
        return;
    }
    if(2*min(a, b) <= max(a, b)){
        cout<<min(a, b)<<"\n";
        return;
    }
    ll ans = 2*(min(a, b)/3);
    ll rem_min = min(a, b) - ans;
    ll rem_max = max(a, b) - 2*ans;
    // 4 7
    if(2*rem_min <= )
    if(a < b){
        a -= ans;
        b -= 2*ans;
    }
    else{
        a -= 2*ans;
        b -= ans;
    }
    if(a == 1 && b == 2 || b == 1 && a == 2){
        ans++;
    }
    cout<<ans<<"\n";
    
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}