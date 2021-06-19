#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    int sum = 0;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum%x != 0){
        cout<<n<<"\n";
        return;
    }
    // start removing from the starting
    int temp_sum = sum;
    int best1 = INT_MIN;
    for(int i =0; i < n; i++){
        if((temp_sum - arr[i]) % x != 0){
            best1 = n - i -1;
            break;
        }
        temp_sum -= arr[i];
    }
    int best2 = INT_MIN;
    temp_sum = sum;
    for(int i = n-1; i >= 0; i--){
        if((temp_sum - arr[i]) % x != 0){
            best2 = i;
            break;
        }
        temp_sum -= arr[i];
    }
    int best3 = INT_MIN;
    temp_sum = sum;
    int low = 0;
    int high = n-1;
    while(low < high){
        if((temp_sum - arr[low])%x != 0){
            best3 = n -low -1;
            // cout<<"YES";
            break;
        }
        if((temp_sum - arr[high])%x != 0){
            best3 = high;
            break;
        }
        if((temp_sum - arr[low] - arr[high])%x != 0){
            best3 = high - low + 1;
            break;
        }
        temp_sum = temp_sum - arr[low] - arr[high];
        low++;
        high--;
    }
    // cout<<best1<<" "<<best2<<" "<<best3<<"\n";
    cout<<max(max(-1,best1), max(best2, best3))<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}