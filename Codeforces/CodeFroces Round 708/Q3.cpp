#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, k;
    cin >> n >> k;
    // 13
    // 8 8 1
    // 18 
    while(k > 3){
        cout << 1 << " ";
        k--;
        n--;
    }
    if(n&1LL){
        n--;
        cout << 1 << " " << n/2 << " " << n/2 << "\n";
        return;
    }
    else{
        if((n/2)&1LL){
            n -= 2;
            cout << 2 << " " << n/2 << " " << n/2 << "\n";
            return;
        }
        cout << n/2 << " " << n/4 << " " << n/4 << "\n";
        return;
    }
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
