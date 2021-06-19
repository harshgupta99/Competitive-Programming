#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<long long int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    // each friend gets either a present or cki dollars
    sort(a.begin(), a.end());
    int idx = 0;
    long long int answer = 0LL;
    while(!a.empty()){
        if(idx >= m){
            answer += b[a.back()];
        }
        else if(b[a.back()] <= b[idx]){
            answer += b[a.back()];
        }
        else{
            answer += b[idx];
            idx++;
        }
        a.pop_back();
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