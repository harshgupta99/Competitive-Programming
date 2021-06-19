//https://codeforces.com/contest/1440/problem/B
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    deque<long long int> a(n*k);
    for(int i = 0; i < n*k; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long int answer = 0LL;
    int cnt = 0;
    int how = (n+1)/2;
    //cout << how << "\n";
    if(n&1){
        ;
    }
    else{
        how++;
    }
    for(int i = (n*k)-how; i >= 0; i -= how){
        answer += a[i];
        ++cnt;
        if(cnt == k){
            break;
        }
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