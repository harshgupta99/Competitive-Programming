#include<bits/stdc++.h>
using namespace std;
long long int k, n, a, b;
bool isPossible(int mid){
    long long int req = mid*a + (n-mid)*b;
    if(k - req > 0){
        return true;
    }
    return false;
}
long long int binarySearch(int low, int high){
    long long int answer;
    while(high >= low){
        int mid = (low + high)/2;
        if(isPossible(mid)){
            answer = mid;
            low = mid + 1;   
        }
        else{
            high = mid -1;
        }
    }
    return answer;
}
void solve(){
    cin >> k >> n >> a >> b;
    if(k - n*b <= 0){
        cout << "-1\n";
        return;
    }
    long long int answer = binarySearch(0, n);
    cout << answer << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}