#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int d;
    cin >> d;
    vector<int> a(n);
    bool ok = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > d){
            ok = false;
        }
    }
    if(ok){
        puts("YES");
        return;
    }
    sort(a.begin(), a.end());
    int s = a[0] + a[1];
    if(s <= d){
        puts("YES");
        return;
    }
    puts("NO");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}