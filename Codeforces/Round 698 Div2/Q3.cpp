//https://codeforces.com/contest/1478/problem/C
#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n;
    cin >> n;
    set<long long int> s;
    set<long long int> S;
    for(int i = 0; i < 2*n; i++){
        long long int x;
        cin >> x;
        if(s.find(x) != s.end()){
            s.erase(x);
        }
        else{
            s.insert(x);
        }
        S.insert(x);
    }
    if(s.size() != 0){
        cout << "NO\n";
        return;
    }
    vector<long long int> a;
    set<long long int> :: iterator it;
    for(it = S.begin(); it != S.end(); it++){
        a.push_back(*it);
    }
    if(a.size() != n){
        cout << "NO\n";
        return;
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    if(a.back() % (2*n)){
        cout << "NO\n";
        return;
    }
    long long int last = a.back()/(2*n);
    long long int sum = 1LL*2*last;
    a.pop_back();
    n--;
    while(!a.empty()){
        long long int curr = a.back();
        a.pop_back();
        if(curr <= sum){
            cout << "NO\n";
            return;
        }
        curr -= sum;
        if(curr % (2*n)){
            cout << "NO\n";
            return;
        }
        curr /= (2*n);
        curr *= 2;
        sum += curr;
        n--;
    }
    cout << "YES\n";
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