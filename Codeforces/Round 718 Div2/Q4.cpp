#include<bits/stdc++.h>
using namespace std;
int n, m, k;
const int mxN = 500*500 + 1;
vector<int> answer(mxN, 1e9);
vector<vector<pair<int, int> > > edges(mxN);
int start;
bool isPossible(int node, int moves){
    int row_node = node/m;
    int col_node = node%m;
    int start_node = start/m;
    int start_col = start%m;
    int dist = abs(row_node - start_node) + abs(col_node - start_col);
    return (dist <= moves);
}
void dfs(int node, int K, int curr){
    if(K == 0 && node == start){
        answer[start] = min(answer[start], curr);
        return; 
    }
    for(auto child : edges[node]){
        if(isPossible(child.first, K-1)){
            dfs(child.first, K-1, curr + child.second);
        }
    }
    return;
}
void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m-1; j++){
            int x = m*i + j;
            int y = m*i + j + 1;
            int z;
            cin >> z;
            edges[x].push_back(make_pair(y, z));
            edges[y].push_back(make_pair(x, z));
        }
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int x = m*i + j;
            int y = m*(i+1) + j;
            int z;
            cin >> z;
            edges[x].push_back(make_pair(y, z));
            edges[y].push_back(make_pair(x, z));
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            start = i*m + j;
            dfs(start, k, 0);
        }
    }
    for(int i = 0; i < n*m; i++){
        if(answer[i] == 1e9){
            answer[i] = -1;
        }
        cout << answer[i] << " ";
        if(i%m == 0){
            cout << "\n";
        }
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