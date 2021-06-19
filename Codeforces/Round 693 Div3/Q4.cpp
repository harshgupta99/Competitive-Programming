#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    priority_queue<long long int> pq;
    for(int i = 0; i < n; i++){
        long long int x;
        cin >> x;
        pq.push(x);
    }
    bool turn = true;
    long long int Alice = 0LL, Bob = 0LL;
    while(!pq.empty()){
        long long int curr = pq.top();
        pq.pop();
        if(turn){
            if(curr&1LL){
                ;
            }
            else{
                Alice += curr;
            }
        }
        else{
            if(curr&1LL){
                Bob += curr;
            }
        }
        turn ^= 1;
    }
    if(Alice > Bob){
        puts("Alice");
        return;
    }
    if(Alice == Bob){
        puts("Tie");
        return;
    }
    puts("Bob");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}