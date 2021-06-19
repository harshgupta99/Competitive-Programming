#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    set<int> s;
    vector<int> extra;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(s.find(x) != s.end()){
            extra.push_back(x);
        }
        else{
            s.insert(x);
        }
    }
    for(auto it : s){
        cout << it << " ";
    }
    for(auto it : extra){
        cout << it << " ";
    }
    cout << "\n";
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