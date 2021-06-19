//https://codeforces.com/gym/102873/problem/F
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int tot = n*n;
    int moves = tot/4;
    int moves_Alice = (moves+1)/2;
    int blocks_Alice = 4 * moves_Alice;
    int blocks_Bob = tot - blocks_Alice;
    if(blocks_Alice == blocks_Bob){
        puts("Draw");
        return;
    }
    if(blocks_Alice > blocks_Bob){
        puts("Alice");
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