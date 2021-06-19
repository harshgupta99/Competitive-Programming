#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w, b;
    cin >> w >> b;
    if(k1 > k2){
        swap(k1, k2);
    }
    int tmp = min(k1, w);
    w -= tmp;
    tmp = min(w, (k2-tmp)/2);
    w -= tmp;
    k1 = n-k1;
    k2 = n-k2;
    if(k1 > k2){
        swap(k1, k2);
    }
    tmp = min(k1, b);
    b -= tmp;
    tmp = min(b, (k2-tmp)/2);
    b -= tmp;
    if(w == 0 && b == 0){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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