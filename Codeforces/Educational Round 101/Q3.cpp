#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // maintain the highest and the lowest 
    long long int low = a[0] + k;
    long long int high = a[0] + k;
    for(int i = 1; i < n-1; i++){
        // they should share atleast 1 length
        if(a[i] >= high){
            puts("NO");
            return;
        }
        if(a[i] + k - 1 + k <= low - k){
            puts("NO");
            return;
        }
        // lowest will be at a[i] + k
        // if still less, then shift up by low - k - a[i] - k + 1
        long long int pos = a[i] + k;
        if(low - k >= pos){
            pos += low - k - pos + 1; 
        }
        low = pos;
        // highest will be at a[i] + k - 1 + k
        // base at min(a[i] + k - 1, high - 1)
        long long int base = min(a[i] + k - 1, high - 1);
        high = base + k;
    }
    long long int last = a.back() + k;
    // should lie anywhere in between low - k + 1 and high - 1
    if(last <= low - k){
        puts("NO");
        return;
    }
    if(a.back() >= high){
        puts("NO");
        return;
    }
    puts("YES");
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}