//https://codeforces.com/contest/1462/problem/E1
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
const int mxN = 4e5+10;
long long int f[mxN];
#define ll long long
void pre(){
    long long int n = 4e5+9;
    f[0] = 1LL;
    for (long long int i = 1; i <= n; i++){
        f[i] = (f[i - 1] * i) % MOD;
        if(f[i] < 0LL){
            f[i] += MOD;
        }
        assert(f[i] > 0LL);
    }
} 
ll pow(ll a, ll b) 
{ 
 ll x=1,y=a;  
 while(b > 0) 
 	{ 
 		if(b%2 == 1) 
 	{ 
 		x=(x*y); 
 		if(x>MOD) x%=MOD; 
 	} 
 	y = (y*y); 
 	if(y>MOD) y%=MOD;  
 	b /= 2; 
 	} 
 return x; 
} 
  
/* Modular Multiplicative Inverse 
 Using Euler's Theorem 
 a^(phi(m)) = 1 (mod m) 
 a^(-1) = a^(m-2) (mod m) */ 
ll InverseEuler(ll n) 
{ 
 return pow(n,MOD-2); 
} 
  
ll C(ll n, ll r) 
{ 
  
 return (f[n]*((InverseEuler(f[r]) * InverseEuler(f[n-r])) % MOD)) % MOD; 
} 
void solve(){
    long long int n;
    cin >> n;
    long long int m, k;
    cin >> m >> k;
    vector<long long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long int answer = 0LL;
    long long int right = 1LL;
    for(long long int left = 0LL; left < n; left++){
        // placing left here and find max right
        right = max(left, right);
        while(right+1 < n && (a[right+1]-a[left]) <= k){
            right++;
        }
        long long int in_between = right - left;
        if(in_between >= (m-1)){
            // tmp+1 C 2
            long long int X = C(in_between, (m-1)) % MOD;
            //cout << in_between << " " << X << "\n";
            if(X < 0){
                X += MOD;
            }
            answer = (answer + X) % MOD;
            if(answer < 0){
                answer += MOD;
            }
        }
        
    }  
    cout << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    pre();
    while(t--){
        solve();
    }
}