#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    char a = 'a';
    while(n){
        n--;
        cout << a;
        a++;
        if(a == 'd'){
            a = 'a';
        }
    }
    puts("");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}