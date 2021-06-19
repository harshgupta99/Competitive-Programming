#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void printDivisors(ll n, ll k) 
{ 
    vector<int> v; 
    for (int i=1; i*i<=n; i++) 
    { 
        if (n%i==0) 
        {
            if(n/i == i){
                v.push_back(n/i);
            }
            else{
                v.push_back(i);
                v.push_back(n/i);
            }
        } 
    }
    sort(v.begin(), v.end());
    for (int i = v.size()-1; i>=0; i--){
        if(v[i] <= k){
            cout<<(n/v[i])<<"\n";
            return;
        }
    }
} 
void solve(){
    ll n, k;
    cin >> n >> k;
    if(k >= n){
        cout<<"1\n";
        return;
    }
    printDivisors(n, k);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}