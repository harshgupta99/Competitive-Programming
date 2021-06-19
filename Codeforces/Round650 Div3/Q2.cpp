#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> odd;
    vector<int> even;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        if(i%2 && (arr[i]%2 == 0)){
            even.push_back(i);
        }
        else if(i%2 == 0 && arr[i]%2 != 0){
            odd.push_back(i);
        }
    }
    if(even.size() != odd.size()){
        cout<<"-1\n";
        return;
    }
    cout<<even.size()<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}