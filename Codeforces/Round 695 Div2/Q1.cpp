#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    if(n == 1){
        puts("9");
        return;
    }
    if(n == 2){
        puts("98");
        return;
    }
    cout << "98";
    int num = 9;
    for(int i = 0; i < n-2; i++){
        cout << num;
        ++num;
        if(num == 10){
            num = 0;
        }
    }
    puts("");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// 98789