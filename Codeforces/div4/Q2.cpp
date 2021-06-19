//https://codeforces.com/gym/102873/problem/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> done(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int prev = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= prev && !done[i]){
            done[i] = true;
            prev = a[i];
        }
        else{
            break;
        }
    }
    prev = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] >= prev && !done[i]){
            done[i] = true;
            prev = a[i];
        }
        else{
            break;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(done[i]){
            ++cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}