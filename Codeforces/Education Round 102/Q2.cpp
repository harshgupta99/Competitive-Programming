#include<bits/stdc++.h>
using namespace std;
void solve(){
    string a, b;
    cin >> a >> b;
    int n = (int)a.size();
    int m = (int)b.size();
    int lcm = n*m/__gcd(n, m);
    //cout << lcm << "\n";
    int cpy = n;
    string tmp = a;
    while(n != lcm){
        n += cpy;
        a += tmp;
    }
    tmp = b;
    cpy = m;
    while(m != lcm){
        m += cpy;
        b += tmp;
    }
    //cout << a << " " << b << "\n";
    string tmp1 = a;
    string tmp2 = b;
    for(int i = 0; i < 50; i++){
        if(a == b){
            cout << a << "\n";
            return;
        }
        a += tmp1;
        b += tmp2;
    }
    puts("-1");
    return;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}