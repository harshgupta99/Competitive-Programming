#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    vector<int> answer;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n-1; i++){
        int curr = arr[i];
        if(curr + n-1 < arr[n-1]){
            continue;
        }
        while(curr < arr[i+1]){
            int cnt1 = 1;
            for(int j = i+1; j < n; j++){
                int cnt = 0;
                while(curr+1 >= arr[j]){
                    j++;
                    cnt++;
                }
                j--;
                cnt1 *= cnt;
            }
            if((i+1)*(cnt1)%p != 0){
                answer.push_back(curr);
            }
            curr++;
        }
    }
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
}