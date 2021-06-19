#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    bool upvote = false;
    int answer = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1 || a[i] == 3){
            ++answer;
        }
    }
    cout << answer << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}