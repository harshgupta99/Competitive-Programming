#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    int grid[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = 0;
        }
    }
    int row_index = 0;
    int col_index = 0;
    int iteration = 1;
    for(int i = 0; i < k; i++){
        grid[row_index][col_index] = 1;
        row_index++;
        col_index++;
        if(row_index == n && col_index != n){
            row_index = 0;
        }
        if(col_index == n){
            col_index = 0;
            row_index = iteration;
            iteration++;
        }
    }
    int row_min = (k/n);
    int row_max;
    if(k%n != 0){
        row_max = k/n + 1;
    }
    else{
        row_max = k/n;
    }
    int col_min = (k/n);
    int col_max;
    if(k%n != 0){
        col_max = k/n + 1;
    }
    else{
        col_max = k/n;
    }
    cout << (row_max - row_min)*(row_max - row_min) + (col_max - col_min)*(col_max - col_min) << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j];
        }
        cout << "\n";
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