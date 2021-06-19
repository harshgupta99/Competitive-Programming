#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    deque<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int miny = *min_element(a.begin(), a.end());
    long long int swaps = 0LL;
    for(int i = 0; i < m; i++){
        if(b[i] < miny){
            swaps += (long long int)n;
        }
    }
    cout << swaps << "\n";
    return;
}
int main(){
    int t = 1;
    while(t--){
        solve();
    }
}