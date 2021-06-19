#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int> > packages(n);
    for(int i = 0; i < n; i++){
        cin >> packages[i].first >> packages[i].second; 
    }
    sort(packages.begin(), packages.end());
    int curr_row = 0;
    int curr_col = 0;
    string answer = "";
    bool ok = true;
    for(int i = 0; i < n; i++){
        pair<int, int> curr_package = packages[i];
        if(curr_row > curr_package.first || curr_col > curr_package.second){
            ok = false;
            break;
        }
        while(curr_row != curr_package.first){
            curr_row++;
            answer += 'R';
        }
        while(curr_col != curr_package.second){
            curr_col++;
            answer += 'U';
        }
    }
    if(ok){
        cout << "YES\n";
        cout << answer << "\n";
        return;
    }
    cout << "NO\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}