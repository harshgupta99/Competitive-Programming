#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, x;
    cin >> n >> x;
    int count_odds = 0;
    int count_even = 0;
    for(int i =0; i < n; i++){
        int y;
        cin >> y;
        if(y%2 == 0){
            count_even++;
        }
        else{   
            count_odds++;
        }
    }
    // odd + even ->
    if(count_odds == 0){
        cout<<"No\n";
        return;
    }
    // we have to choose x-1 elements having even elements which means choosing any number of even element or even number of odd elements
    x--;
    count_odds--;
    int odd_elements = count_odds/2;
    // choose these many pairs of odd elements
    while(x-2 >= 0 && odd_elements > 0){
        x -= 2;
        odd_elements--;
    }
    if(x == 0){
        cout<<"Yes\n";
        return;
    }
    if(count_even >= x){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
    return;


}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}