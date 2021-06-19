#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int* athletes = new int[n];
    for(int i =0; i < n; i++){
        cin >> athletes[i];
    }
    sort(athletes, athletes + n);
    int answer = INT_MAX;
    for(int i =1 ; i < n; i++){
        int curr_diff = abs(athletes[i-1] - athletes[i]);
        answer = min(answer, curr_diff);
    }
    cout<<answer<<"\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}