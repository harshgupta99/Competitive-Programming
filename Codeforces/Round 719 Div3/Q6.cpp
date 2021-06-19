#include<bits/stdc++.h>
using namespace std;
#define int long long int
int query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}
signed main(){
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int high = n, low = 1;
    while(high >= low){
        int mid = (low + high) / 2;
        int x = query(low, mid);
        int len = (mid - low + 1);
        int num_zeros = len - x;
        if(len == 1 && num_zeros == 1 && k == 1){
            cout << "! " << mid << "\n";
            fflush(stdout);
            return 0;
        }
        if(num_zeros >= k){
            high = mid;
        }
        else{
            k -= num_zeros;
            low = mid + 1;
            if(low == high + 1){
                high++;
            }
        }
        len = (high - low + 1); 
    }
    assert(false);
    return 0;
}
// 101001