//https://codeforces.com/contest/1478/problem/0
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        bool used = false;
        int mx = 0;
        for(int j = 0; j < n; j++){
            if(a[j] == -1){
                continue;
            }
            if(a[j] > mx){
                mx = max(a[j], mx);
                a[j] = -1;
                used = true;
            }
        }
        if(!used){
            break;
        }
        ++cnt;
    }
    cout << cnt << "\n";
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