#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int GCD = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    for(int i = 0; i < n; i++){
        arr[i] = abs(arr[n-1] - arr[i]);
        sum += arr[i];
        GCD = __gcd(GCD, arr[i]);
    }
    cout << sum/GCD << " " << GCD << "\n";
    return 0;
}