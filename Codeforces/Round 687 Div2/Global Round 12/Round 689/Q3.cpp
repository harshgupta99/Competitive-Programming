//https://codeforces.com/contest/1461/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int limit = n;
    int bck = n-1;
    while(limit >= 1 && a[bck] == limit){
        limit--;
        bck--;
    }
    double answer = 0;
    double not_sorted = 1;
    while(m--){
        int x;
        cin >> x;
        double p;
        cin >> p;
        if(x < limit){
            continue;
        }
        answer += (not_sorted)*(p);
        not_sorted *= (1 - p);
    }
    if(is_sorted(a.begin(), a.end())){
        puts("1.0000000000");
        return;
    }
    cout << setprecision(10) << fixed << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}