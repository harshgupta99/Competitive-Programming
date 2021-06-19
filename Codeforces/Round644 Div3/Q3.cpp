#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int low, int high, vector<int> arr, int element){
    while(high >= low){
        int mid = (high+ low)/2;
        if(arr[mid] == element+1 || arr[mid] == element - 1){
            return true;
        }
        else if(arr[mid] > element){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return false;
}
void solve(){
    int n;
    cin >> n;
    int count_even = 0;
    int count_odd = 0;
    vector<int> even;
    vector<int> odd;
    for(int i =0; i < n; i++){
        int x;
        cin >> x;
        if(x % 2){
            odd.push_back(x);
            count_odd++;
        }
        else{
            even.push_back(x);
            count_even++;
        }
    }
    if((count_even %2 == 0)  && (count_odd % 2 == 0)){
        cout<<"YES\n";
        return;
    }
    if((count_even%2 == 0 && count_odd%2 != 0) || (count_even%2 != 0 && count_odd%2 == 0)){
        cout<<"NO\n";
        return;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for(int i =0; i < odd.size(); i++){
        if(BinarySearch(0, even.size()-1, even, odd[i])){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}