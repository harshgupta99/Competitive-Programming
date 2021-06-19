#include<bits/stdc++.h>
using namespace std;
void solve(){
    int a, b;
    cin >> a >> b;
    if(a <= 1 && b <=1){
        cout<<"0\n";
        return;
    }
    if(a == b){
        int ans = a/2;
        int rem = a%2;
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
    int ans = max(a, b)/2;
    if(a%2){
        ans++;
    }
    else if(b%2){
        ans++;
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    // 9 7 7 6 5 5 
    while(t--){
        solve();
    }
}