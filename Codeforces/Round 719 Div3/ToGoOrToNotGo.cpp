#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mxN = 2e3 + 10;
int n, m, w;
vector<vector<int> > grid(mxN, vector<int> (mxN));
bool isValid(int row, int col, vector<vector<int> > &dist){
    if(row >= 0LL && col >= 0LL && row < n && col < m && dist[row][col] == 1e18 && grid[row][col] != -1LL){
        return true;
    }
    return false;
}
void bfs(int row, int col, vector<vector<int> > &dist){
    queue<pair<int, int> > q;
    q.push({row, col});
    dist[row][col] = 0LL;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();
        if(isValid(r-1, c, dist)){
            dist[r-1][c] = dist[r][c] + 1;
            q.push({r-1, c});
        }
        if(isValid(r, c-1, dist)){
            dist[r][c-1] = dist[r][c] + 1;
            q.push({r, c-1});
        }
        if(isValid(r+1, c, dist)){
            dist[r+1][c] = dist[r][c] + 1;
            q.push({r+1, c});
        }
        if(isValid(r, c+1, dist)){
            dist[r][c+1] = dist[r][c] + 1;
            q.push({r, c+1});
        }
    }
    return;
}
void solve(){
    cin >> n >> m >> w;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int> > dist1(n, vector<int> (m, 1e18));
    vector<vector<int> > dist2(n, vector<int> (m, 1e18));
    bfs(0, 0, dist1);
    bfs(n-1, m-1, dist2);
    int answer = 1e18;
    if(dist1[n-1][m-1] != 1e18){
        answer = dist1[n-1][m-1] * w;
    }
    int best_from_end = 1e18;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] >= 1LL && dist2[i][j] != 1e18){
                best_from_end = min(best_from_end, dist2[i][j] * w + grid[i][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] >= 1L && dist1[i][j] != 1e18){
                answer = min(answer, grid[i][j] + w * dist1[i][j] + best_from_end);
            }
        }
    }
    if(answer == 1e18){
        cout << "-1\n";
    }
    else{
        cout << answer << "\n";
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_cases = 1;
    for(int tt = 1; tt <= test_cases; tt++){
        solve();
    }
}