//https://codeforces.com/contest/1475/problem/E
#include<bits/stdc++.h>
using namespace std;
#define p 1000000007
long long int power(long long int x,long long int y){
    long long int res = 1LL;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
long long int modInverse(long long int n){
    return power(n, p - 2);
}
long long int nCrModPFermat(long long int n, long long int r){
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    long long int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r]) % p * modInverse(fac[n - r]) % p) % p;
}
long long int nCrModp(long long int n, long long int r) 
{ 
    // Optimization for the cases when r is large 
    if (r > n - r) 
        r = n - r; 
  
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    long long int C[r + 1]; 
    memset(C, 0LL, sizeof(C)); 
  
    C[0] = 1LL; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (long long int i = 1; i <= n; i++) { 
  
        // Fill entries of current row using previous 
        // row values 
        for (long long int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j - 1]) % p; 
    } 
    return C[r]; 
} 
void solve(){
    long long int n, k;
    cin >> n >> k;
    map<long long int, long long int> mp;
    for(int i = 0; i < n; i++){
        long long int x;
        cin >> x;
        mp[x]++;
    }
    long long int answer = 0LL;
    map<long long int, long long int> :: reverse_iterator it;
    for(it = mp.rbegin(); it != mp.rend(); it++){
        if(it->second < k){
            k -= it->second;
            continue;
        }
        answer += nCrModp(it->second, 1LL * k);
        break;
    }
    cout << answer << "\n";
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