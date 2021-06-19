//https://codeforces.com/contest/1447/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<long long int> > grid(n, vector<long long int> (m));
    int cnt = 0;
    bool zero = false;
    long long int sum = 0;
    long long int miny = 1e18;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            sum += abs(grid[i][j]);
            cnt += (grid[i][j] < 0);
            zero |= (grid[i][j] == 0);
            miny = min(miny, abs(grid[i][j]));
        }
    }
    if(zero){
        cout << sum << "\n";
        return;
    }
    if(cnt%2 == 0){
        cout << sum << "\n";
        return;
    }
    sum -= miny;
    cout << sum - miny << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}