#include<bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 10;
vector<vector<int> > edges(mxN);
vector<int> parent(mxN);
pair<int, int> dfs(int node, int par = -1, int dist = 0){
    parent[node] = par;
    pair<int, int> res = make_pair(dist, node);
    for(int child : edges[node]){
        if(child == par)
            continue;
        res = max(res, dfs(child, node, dist + 1));
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    pair<int, int> da = dfs(0);
    pair<int, int> db = dfs(da.second);
    vector<int> diam;
    int v = db.second;
    while(v != da.second){
        diam.push_back(v);
        v = parent[v];
    }
    diam.push_back(da.second);
    if(diam.size() == n){
        cout << n - 1 << "\n";
        cout << diam[0] + 1 << " " << diam[1] + 1 << " " << diam.back() + 1 << "\n";
        return 0; 
    }
    // multi source bfs
    queue<int> q;
    vector<int> dist(n, -1);
    for(auto v : diam){
        dist[v] = 0;
        q.push(v);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child : edges[curr]){
            if(dist[child] == -1){
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
    pair<int, int> mx = make_pair(dist[0], 0);
    for(int v = 1; v < n; v++){
        mx = max(mx, make_pair(dist[v], v));
    }
    cout << (int)diam.size() - 1 + mx.first << "\n";
    cout << diam[0] + 1 << " " << mx.second + 1 << " " << diam.back() + 1 << "\n";
    return 0; 

}