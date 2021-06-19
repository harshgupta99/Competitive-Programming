//https://codeforces.com/gym/102942/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    while(!a.empty() && a.back() >= k){
        ++cnt;
        a.pop_back();
    }
    int lft = 0;
    int rgt = a.size()-1;
    while(lft < rgt){
        if(a[rgt] + a[lft] >= k){
            rgt--;
            lft++;
            ++cnt;
        }
        else{
            lft++;
        }
    }
    cout << cnt << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}