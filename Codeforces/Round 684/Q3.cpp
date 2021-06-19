#include<bits/stdc++.h>
using namespace std;
struct Operation{
    vector<pair<int, int> > coord;
};
vector<Operation> op;
vector<string> grid;
void flip(int x, int y){
    if(grid[x][y] == '0'){
        grid[x][y] = '1';
    }
    else{
        grid[x][y] = '0';
    }
    return;
}
void Add(int x1, int y1, int x2, int y2, int x3, int y3){
    Operation nxt;
    nxt.coord.push_back(make_pair(x1, y1));
    nxt.coord.push_back(make_pair(x2, y2));
    nxt.coord.push_back(make_pair(x3, y3));
    flip(x1, y1);
    flip(x2, y2);
    flip(x3, y3);
    op.push_back(nxt);
}
void solve(){
    int n, m;
    cin >> n >> m;
    grid.resize(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    for(int i = 0; i <= n-2; i++){
        for(int j = 0; j <= m-2; j++){
            // consider this square
            // Case 1: 0 0 0 0
            if(i != n-2){
                if(grid[i][j] == '0' && grid[i][j+1] == '0'){
                    continue;
                }
                else if(grid[i][j] == '1' && grid[i][j+1] == '1'){
                    if(grid[i+1][j] == '1'){
                        Add(i, j, i, j+1, i+1, j);
                    }
                    else if(grid[i+1][j+1] == '1'){
                        Add(i, j, i, j+1, i+1, j+1);
                    }
                    else{
                        Add(i, j, i, j+1, i+1, j);
                    }
                }
                else if(grid[i][j] == '1'){
                    Add(i, j, i+1, j, i+1, j+1);
                }
                else{
                    Add(i, j+1, i+1, j, i+1, j+1);
                }
                continue;
            }
            while(true){
                int cnt = 0;
                vector<pair<int, int> > zeros;
                vector<pair<int, int> > ones;
                if(grid[i][j] == '0'){
                    ++cnt;
                    zeros.push_back(make_pair(i, j));
                }
                else{
                    ones.push_back(make_pair(i, j));
                }
                if(grid[i+1][j] == '0'){
                    ++cnt;
                    zeros.push_back(make_pair(i+1, j));
                }
                else{
                    ones.push_back(make_pair(i+1, j));
                }
                if(grid[i][j+1] == '0'){
                    ++cnt;
                    zeros.push_back(make_pair(i, j+1));
                }
                else{
                    ones.push_back(make_pair(i, j+1));
                }
                if(grid[i+1][j+1] == '0'){
                    ++cnt;
                    zeros.push_back(make_pair(i+1, j+1));
                }
                else{
                    ones.push_back(make_pair(i+1, j+1));
                }
                if(cnt == 4){
                    break;
                }
                if(cnt == 0){
                    // select any three
                    Add(i, j, i+1, j, i+1, j+1);
                }
                else if(cnt == 3){
                    // select 2 zeros and 1
                    if(zeros.size() < 2 || ones.size() < 1){
                        cout << "NOO1";
                        return;
                    }
                    int x1 = zeros.back().first;
                    int y1 = zeros.back().second;
                    zeros.pop_back();
                    int x2 = zeros.back().first;
                    int y2 = zeros.back().second;
                    Add(x1, y1, x2, y2, ones.back().first, ones.back().second);
                }
                else if(cnt == 2){
                    if(zeros.size() < 2 || ones.size() < 1){
                        cout << "NOO2";
                        return;
                    }
                    int x1 = zeros.back().first;
                    int y1 = zeros.back().second;
                    zeros.pop_back();
                    int x2 = zeros.back().first;
                    int y2 = zeros.back().second;
                    Add(x1, y1, x2, y2, ones.back().first, ones.back().second);
                }
                else{
                    // select 3 ones
                    if(ones.size() < 3){
                        cout << "NOO3";
                        return;
                    }
                    int x1 = ones.back().first;
                    int y1 = ones.back().second;
                    ones.pop_back();
                    int x2 = ones.back().first;
                    int y2 = ones.back().second;
                    ones.pop_back();
                    Add(x1, y1, x2, y2, ones.back().first, ones.back().second);
                }
                --cnt;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            assert(grid[i][j] == '0');
        }
    }
    assert(op.size() <= 3*n*m);
    cout << (int)op.size() << "\n";
    for(int i = 0; i < (int)op.size(); i++){
        for(int j = 0; j < 3; j++){
            cout << op[i].coord[j].first + 1 << " " << op[i].coord[j].second + 1 << " ";
        }
        cout << "\n";
    }
    op.clear();
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}