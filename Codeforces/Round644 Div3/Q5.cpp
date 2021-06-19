#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<string> grid;
    for(int i =0; i < n;i++){
        string s;
        cin >>s;
        grid.push_back(s);
    }
    for(int i =0; i < n-1; i++){
        for(int j =0;j < n-1; j++){
            if(grid[i][j] == '1'){
                if(grid[i+1][j] == '0' && grid[i][j+1]== '0'){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}