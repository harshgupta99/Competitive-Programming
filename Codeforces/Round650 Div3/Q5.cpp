#include<bits/stdc++.h>
using namespace std;
int k, n;
map<char, int> mp;
int solve(){
    for(int i = n ; i >= 1; i--){
        int tmp = k;
        k %= i;
        int av = 0;
        int gcd = __gcd(i, k);
        int need = i/gcd;
        for(auto x : mp){
            av += x.second/need;
        }
        if(av*need >= i){
            return i;
        }
        k = tmp;
    }
}
int main(){
    int q;
    cin >> q;
    while(q--){
        cin >> n >> k;
        string s;
        cin >> s;
        mp.clear();
        for(int i =0; i < n; i++){
            mp[s[i]]++;
        }
        cout<< solve() << "\n";
    }
}