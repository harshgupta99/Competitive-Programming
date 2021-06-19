#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = i+1;
    }
    for(int i = 0; i < n-1; i++){
        swap(a[i], a[i+1]);
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    puts("");
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