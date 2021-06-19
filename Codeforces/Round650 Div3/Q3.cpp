#include<bits/stdc++.h>
using namespace std;
int n, k;
void solve(){
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ones;
    for(int i =0; i < n; i++){
        if(s[i] == '1'){
            ones.push_back(i);
        }
    }
    int cnt = 0;
    if(ones.size() == 0){
        for(int i =0; i < n; i+=k+1){
            cnt++;
        }
        cout<<cnt<<"\n";
        return;
    }
    for(int i = ones[0]-k-1; i >= 0; i -= (k+1)){
        cnt++;
    }
    for(int i = ones[ones.size()-1]+k+1; i < n; i += k+1){
        cnt++;
    }
    for(int i = 0; i < ones.size()-1; i++){
        int left_anchor = ones[i]+k+1;
        int right_anchor = ones[i+1];
        while(left_anchor <= right_anchor-k-1){
            cnt++;
            left_anchor += k+1;
        }
    }
    cout<<cnt<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}