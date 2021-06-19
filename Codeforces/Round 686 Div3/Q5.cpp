//https://codeforces.com/contest/1454/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    const int mxN = 2e5+10;
    vector<int> cnt(mxN, 0);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
        cnt[x]++;
    }
    for(int i = 1; i < mxN; i++){
        if(cnt[i] == 1){
            for(int j = 0; j < n; j++){
                if(a[j] == i){
                    cout << j+1 << "\n";
                    return;
                }
            }
        }
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