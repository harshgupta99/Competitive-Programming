//https://codeforces.com/contest/1451/problem/D
#include<bits/stdc++.h>
using namespace std;
long long int d, k;
bool isValid(long long int curr_x, long long int curr_y){
    return (((curr_x + k) *( curr_x + k) + (curr_y + k) * (curr_y + k)) <= (d * d));
}
void solve(){
    cin >> d >> k;
    long long int X = 0, Y = 0;
    while(isValid(X, Y)){
        X += k;
        Y += k;
    }
    long long int hor_dist = (X+k)*(X+k) + Y*Y;
    long long int ver_dist = (X*X) + (Y+k)*(Y+k);
    if(hor_dist <= d*d || ver_dist <= d*d){
        puts("Ashish");
        return;
    }
    puts("Utkarsh");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}