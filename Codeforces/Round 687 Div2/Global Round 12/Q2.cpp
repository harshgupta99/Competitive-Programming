//https://codeforces.com/contest/1450/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    bool ok = false;
    for(int i = 0; i < n; i++){
        pair<int, int> p = a[i];
        bool this_ = true;
        for(int j = 0; j < n; j++){
            if(abs(a[j].first - p.first) + abs(a[j].second - p.second) > k){
                this_ = false;
                break;
            }
        }
        if(this_){
            ok = true;
            break;
        }
    }
    if(ok){
        puts("1");
        return;
    }
    puts("-1");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}