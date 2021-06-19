#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> colors(51, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(colors[a[i]] == -1){
            colors[a[i]] = i; 
        }
    }
    while(q--){
        int x;
        cin >> x;
        cout << colors[x]+1 << " "; 
        for(int i = 1; i <= 50; i++){
            if(colors[i] < colors[x] && colors[i] != -1){
                colors[i]++;
            }
        }
        colors[x] = 0;
    }
    cout << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}