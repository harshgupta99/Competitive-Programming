#include<bits/stdc++.h>
using namespace std;
int main(){
    int c, d, x;
    cin >> c >> d >> x;
    int cnt = 0;
    for(int i = 1; i <= 1e3; i++){
        for(int j = 1; j <= 1e3; j++){
            if((c*i*j/__gcd(i, j) - d*__gcd(i, j)) == x){
                cout << i << " " << j << "\n";
                ++cnt;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}