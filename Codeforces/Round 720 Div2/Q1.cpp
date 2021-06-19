#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int a, b;
    cin >> a >> b;
    if(a%b == 0LL){
        cout << "\n";
        return;
    }
    b *= 10;
    for(int i = 1; i < b; i++){
        if(((b-i)*a)%b != 0LL && (i*a)%b != 0LL && i*a != (b-i)*a){
            cout << "YES\n";
            cout << i*a << " " << (b-i)*a << " " << a*b << "\n"; 
            return;
        }
    }
    cout << "NO\n";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases;
    cin >> test_cases;
    for(int tt = 1; tt <= test_cases; tt++){
        solve();
    }
}
//