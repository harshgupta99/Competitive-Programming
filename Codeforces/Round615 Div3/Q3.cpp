#include<bits/stdc++.h>
using namespace std;
int cnt;
vector<pair<int, int> > answer;
bool helper(int n, int prev){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0 && i != prev){
            answer.push_back(make_pair(i, n/i));
            cnt++;
            return true;
        }
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    answer.clear();
    cnt = 0;
    if(!helper(n, -1)){
        cout << "NO\n";
        return;
    }
    if(!helper(answer[0].second, answer[0].first)){
        cout << "NO\n";
        return;
    }
    if(answer[0].first == answer[1].second || answer[1].first == answer[1].second){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << answer[0].first << " " << answer[1].first << " " << answer[1].second << "\n";
    return;   
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}