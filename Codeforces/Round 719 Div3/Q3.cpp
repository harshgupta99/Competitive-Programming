#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;
    cin >> n;
    if(n == 2){
        cout << "-1\n";
        return;
    }
    if(n == 1){
        cout << "1\n";
        return;
    }
    vector<vector<int> > grid(n, vector<int> (n));
    assert(n >= 3LL);
    int first = 1, last = n*n;
    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++, ok ^= 1){
            if(ok){
                grid[i][j] = first++;
            }
            else{
                grid[i][j] = last--;
            }
        }
    }
    swap(grid[n-1][n-1], grid[n-2][n-1]);
    if(n == 3LL){
        swap(grid[1][0], grid[2][2]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_cases;
    cin >> test_cases;
    for(int tt = 1; tt <= test_cases; tt++){
        solve();
    }
}