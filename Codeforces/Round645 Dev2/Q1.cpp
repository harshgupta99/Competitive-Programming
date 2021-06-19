#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    long long int answer = (n*m)/2;
    if((n*m)%2){
        answer++;
    }
    cout<<answer<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}