#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for(int i =0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int max_answer = 1;
    int curr_count = 1;
    for(int i =0; i < n; i++){
        if(curr_count + 1 > v[i]){
            max_answer = curr_count + 1;
        }
        curr_count++;
    }
    cout<<max_answer<<"\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}