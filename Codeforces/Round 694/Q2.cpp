#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, x;
    cin >> n >> x;
    vector<pair<long long int, long long int> > a;
    long long int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        a.push_back(make_pair(t, 1));
    }
    // 12 6 6 3 3 3 3
    // 4 
    int idx = 0;
    long long int answer = 0LL;
    while(idx != a.size()){
        if(a[idx].first%x){
            break;
        }
        a.push_back(make_pair(a[idx].first/x, x*a[idx].second));
        idx++;
    }
    for(int i = 0; i < (int)a.size(); i++){
        answer += (long long int)(a[i].first)*(a[i].second);
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