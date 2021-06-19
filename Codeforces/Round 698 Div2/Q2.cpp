//https://codeforces.com/contest/1478/problem/C
#include<bits/stdc++.h>
using namespace std;
bool check(int n, int d){
    while(n){
        if(n%10 == d){
            return true;
        }
        n /= 10;
    }
    return false;
}
void solve(){
    int n, d;
    cin >> n >> d;
    while(n--){
        int x;
        cin >> x;
        if(x >= 10*d){
            cout << "YES\n";
            continue;
        }
        int cnt = x / d;
        int rem = x % d;
        vector<int> a(cnt, d);
        if(a.size() == 0){
            a.push_back(rem);
        }
        else{
            a.back() += rem;
        }
        bool ok = false;
        while(!a.empty()){
            if(check(a.back(), d)){
                cout << "YES\n";
                ok = true;
                break;
            }
            int tmp = a.back();
            a.pop_back();
            if(!a.empty()){
                a.back() += tmp;
            }
        }
        if(!ok)
            cout << "NO\n";
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// 200 
// 100 = 14*7 + 2 -> 