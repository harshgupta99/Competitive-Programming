#include<bits/stdc++.h>
using namespace std;
int primes[9] = {3, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 1000000007}
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a < b){
        if(c == a){
            int x = 1;
            int sz = 1;
            while(sz != a){
                sz++;
                x *= 10;
            }
            int y = 1;
            sz = 1;
            while(sz != b){
                sz++;  
                y *= 10;
            }
            cout << x << " " << y << "\n";
            return;
        }
        // int gcd = 9;
        // int sz = 1;
        // while(sz != c){
        //     gcd *= 10; 
        //     gcd += 9;
        //     sz++; 
        // }
        // assert(sz == c);
        int gcd = primes[c-1];
        int x = gcd*(primes[a-c]);
        int y = gcd*(primes[b-c]);
        // while(__gcd(x, y) != gcd){
        //     y += gcd;
        // }
        // assert(__gcd(x, y) == gcd);
        cout << x << " " << y << "\n";
    }
    else{
        if(c == b){
            int x = 1;
            int sz = 1;
            while(sz != a){
                sz++;
                x *= 10;
            }
            int y = 1;
            sz = 1;
            while(sz != b){
                sz++;  
                y *= 10;
            }
            cout << x << " " << y << "\n";
            return;
        }
        // int gcd = 9;
        // int sz = 1;
        // while(sz != c){
        //     gcd *= 10; 
        //     gcd += 9;
        //     sz++; 
        // }
        // assert(sz == c);
        int gcd = primes[c-1];
        int x = gcd*(primes[a-c]);
        int y = gcd*(primes[b-c]);
        // while(__gcd(x, y) != gcd){
        //     x += gcd;
        // }
        // assert(__gcd(x, y) == gcd);
        cout << x << " " << y << "\n";
        return;

    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}