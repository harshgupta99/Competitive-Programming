#include<bits/stdc++.h>
using namespace std;
int n, m;
const int mxN = 2e5+10;
vector<vector<int> > edges(mxN);
vector<int> dist(mxN, 1e9);
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    queue<pair<int, int> > q;
    q.push(make_pair(1, 0));
    dist[1] = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        for(auto x : edges[curr]){
            if(dist[x] > curr.second+1){
                dist[x] = curr.second+1;
                q.push(make_pair(x, curr.second+1));
            }
        }
    }
    vector<int> answer(n+1, -1);
    for(int i = 1; i <= n; i++){
        int ans = dist[i];
        for(auto x: edges[i]){
            ans = min(ans, dist[x]);
        }
        answer[i] = ans;
    }
    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
    return;
}
void init(){
    for(int i = 1; i <= n; i++){
        edges[i].clear();
        dist[i] = 1e9;
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        init();
    }
}