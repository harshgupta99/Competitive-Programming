#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int increase = 0;
    for(int i = 0; i < n-1; i++){
        int extra = a[i];
        if(extra >= k){
            a[i] -= k;
            increase += k;
            break;
        }
        else{
            a[i] = 0;
            increase += extra;
            k -= extra;
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] + increase << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}