#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
void dfs(int rem, vector<vector<int> > &A, int row, int col){
    if(rem == 0){
        return;
    }
    A[row][col] = cnt;
    if(row+1 < n && A[row+1][col] == -1){
        dfs(rem-1, A, row+1, col);
    }
    else if(col-1 >= 0 && A[row][col-1] == -1){
        dfs(rem-1, A, row, col-1);
    }
    else if(row-1 >= 0 && A[row-1][col] == -1){
        dfs(rem-1, A, row-1, col);
    }
    else{
        assert(rem == 1);
    }
    return;
}
void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int> > A(n, vector<int> (n, -1));
    for(int i = n-1; i >= 0; i--){
        // try going down and then left
        cnt = a[i];
        dfs(a[i], A, i, i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}