#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr(200006);
bool isPeak(int index){
    if(arr[index - 1] < arr[index] && arr[index] > arr[index + 1]){
        return true;
    }
    return false;
}
bool isValley(int index){
    if(arr[index - 1] > arr[index] && arr[index] < arr[index + 1]){
        return true;
    }
    return false;
}
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> answer;
    answer.push_back(arr[0]);
    for(int i = 1; i < n-1; i++){
        if(isPeak(i) || isValley(i)){
            answer.push_back(arr[i]);
        }
    }
    answer.push_back(arr[n-1]);
    cout<<answer.size()<<"\n";
    for(int i =0; i < answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    cout<<"\n";
    arr.clear();
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}