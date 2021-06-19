#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    // start by filling the rows
    int* visited_cols = new int[m];
    for(int i =0; i < m; i++){
        visited_cols[i] = 0;
    }
    bool ok = true;
    int grid[n][m];
    for(int i =0; i < n; i++){
        for(int j =0 ; j < m; j++){
            grid[i][j] = 0;
        }
    }
    for(int i =0; i < n; i++){
        // fill a in the first
        int count = 0;
        int j;
        int ref;
        if(i > m - 1){
            j = 0;
        }
        else{
            j = i;
        }
        ref = j-1;
        for(; j < m; j++){
            if(j == ref + 1){
                break;
            }
            if(j == m - 1){
                j = -1;
                continue;
            }
            if(visited_cols[j] < b){
                visited_cols[j]++;
                grid[i][j] = 1;
                count++;
            }
            if(count == a){
                break;
            }
        }
        if(count != a){
            cout<<"NO\n";
            return;
        }
    }
    for(int i=0; i < m; i++){
        if(visited_cols[i] != b){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for(int i =0; i < n; i++){
        for(int j =0; j < m; j++){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}