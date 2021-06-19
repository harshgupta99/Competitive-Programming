//https://codeforces.com/gym/102942/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt_odd = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]&1){
            ++cnt_odd;
        }
        else{
            cnt++;
        }
    }
    if(cnt_odd == 0){
        cout << "-1\n";
        return;
    }
    cout << cnt << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}