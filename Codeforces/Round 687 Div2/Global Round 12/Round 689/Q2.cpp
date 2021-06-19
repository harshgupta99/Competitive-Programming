//https://codeforces.com/contest/1461/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            grid[i].push_back('*');
        }
    }
    // consider i, j as the origin
    long long int answer = 0LL;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == '.'){
                continue;
            }
            // consider (row, col) as the origin and find the number of spruce trees
            int length = 0;
            while(true){
                bool ok = true;
                if((row-length) < 0){
                    break;
                }
                if((col - length) < 0 || (col + length) >= m){
                    break;
                }
                int tmp = length;
                for(int k = row; tmp >= 0; tmp--, k--){
                    if(grid[k][col-tmp] == '.'){
                        ok = false;
                        break;
                    }
                    if(grid[k][col+tmp] == '.'){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    ++answer;
                }
                else{
                    break;
                }
                length++;
            }
        }
    }
    cout << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}