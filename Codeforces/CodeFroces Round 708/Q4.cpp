#include<bits/stdc++.h>
using namespace std;
int prime[10000001] = { 0 }; 
int k[10000001] = { 0 }; 
void Sieve(){ 
    for (int i = 1; i < 10000001; i++) 
        k[i] = i; 
    for (int i = 2; i < 10000001; i++) { 
        if (prime[i] == 0) 
            for (int j = i; j < 10000001; j += i) { 
                prime[j] = 1;
                while (k[j] % (i * i) == 0) 
                    k[j] /= (i * i); 
            } 
    } 
} 
void solve(){
    int n, z;
    cin >> n >> z;
    int x;
    int cnt = 1;
    set<int> active;
    for(int i = 0; i < n; i++){
        cin >> x;
        int curr = k[x];
        if(active.find(curr) != active.end()){
            ++cnt;
            active.clear();
            active.insert(curr);
        }
        else{
            active.insert(curr);
        }
    }
    cout << cnt << "\n";
    return;
}   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Sieve();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
