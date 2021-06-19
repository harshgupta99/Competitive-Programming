//https://codeforces.com/contest/1474/problem/C
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
       int n;
        cin >> n;
        n *= 2;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        // for(int i = 0; i < n; i++){
        //     cout << a[i] << " ";
        // }
        sort(a.begin(), a.end());
        vector<pair<int, int> > answer;
        bool done = false;
        int initial;
        // see for checking
        for(int i = 0; i < n-1; i++){
            // consider this as the starting element
            answer.clear();
            map<int, int> freq = mp;
            freq[a.back()]--;
            answer.push_back(make_pair(a.back(), a[i]));
            freq[a[i]]--;
            initial = a.back() + a[i];
            // now see if the process can be completed
            int cnt = 1;
            int pivot = a.back();
            int right = n-2;
            while(cnt != n/2){
                // try making pivot with the greatest element
                while(right >= 0 && freq[a[right]] == 0){
                    right--;
                }
                int need = pivot - a[right];
                freq[a[right]]--;
                if(freq[need] > 0){
                    freq[need]--;
                    ++cnt;
                    answer.push_back(make_pair(a[right], need));
                    pivot = max(need, a[right]);
                }
                else{
                    break;
                }
            }
            if(cnt == n/2){
                done = true;
                break;
            }
        }
        if(!done){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << initial << "\n";
        for(int i = 0; i < (int)answer.size(); i++){
            cout << answer[i].first << " " << answer[i].second << "\n";
        }
    }
}