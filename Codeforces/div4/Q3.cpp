//https://codeforces.com/gym/102873/problem/C
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mid = a[n/2];
    int mid2 = a[n/2 + 1];
    long long int best = 1e18;
    for(int i = mid-2; i <= mid+2; i++){
        long long int curr = 0LL;
        for(int j = 0; j < n; j++){
            curr += (long long int)(abs(a[j] - i));
        }
        best = min(best, curr);
    }
    for(int i = mid2-2; i <= mid2+2; i++){
        long long int curr = 0LL;
        for(int j = 0; j < n; j++){
            curr += (long long int)(abs(a[j] - i));
        }
        best = min(best, curr);
    }
    cout << best << "\n";
    return 0;
}