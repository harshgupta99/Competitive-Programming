#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int w, h, n;
    cin >> w >> h >> n;
    long long int cnt = 1LL;
    long long int num = 1LL;
    while(w%2 == 0){
        w /= 2;
        num *= 2;
    }
    while(h%2 == 0){
        h /= 2;
        num *= 2;
    }
    //cout << cnt << "\n";
    if(n <= num){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}