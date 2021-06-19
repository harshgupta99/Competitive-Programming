//https://codeforces.com/contest/1462/problem/0
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int left = 0, right = n-1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> answer(n);
    for(int i = 0; i < n; i++){
        if(i&1){
            answer[i] = a[right--];
        }
        else{
            answer[i] = a[left++];
        }
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}