#include<bits/stdc++.h>
using namespace std;
int A, B, C;
void checker(int a, int b, int c){
    if(a >= b && a >= c){
        A = a;
        if(b >= c){
            B = b;
            C = c;
        }
        else{
            B = c;
            C = b;
        }
    }
    else if(b >= a && b >= c){
        A = b;
        if(a >= c){
            B = a;
            C = c;
        }
        else{
            B = c;
            C = a;
        }
    }
    else if(c >= b && c >= a){
        A = c;
        if(b >= a){
            B = b;
            C = a;
        }
        else{
            B = a;
            C = b;
        }
    }
}
void solve(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    checker(a, b, c);
    int req = (A - B) + (A-C);
    if(req > n){
        cout << "NO\n";
        return;
    }
    n -= req;
    if(n%3 == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
    return;
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}