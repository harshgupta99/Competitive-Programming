#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> cnt(n+1), 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    long long int sum = 0;
    sort(cnt.rbegin(), cnt.rend());
    int last = cnt[0];
    sum += cnt[0];
    for(int i = 2; i <= n; i++){
        if(cnt[i] < last){
            sum += cnt[i];
        }
        else{
            sum += last-1;
            last = last-1;
        }
    }
    cout << sum << "\n";
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