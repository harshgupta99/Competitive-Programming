#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    set<int> use;
    for(int i =0; i <= arr[n-1]+2; i++){
        use.insert(i);
    }
    if(!(is_sorted(arr.begin(), arr.end()))){
        cout<<"-1\n";
        return 0;
    }
    // 1 2 3
    // 0 
    multiset<int> B; 
    vector<int> ans;
    int prev;
    // if all elements below that are already taken then add the one with abve it
    for(int i =0; i < n; i++){
        // we need all the elements before a[i]
        int curr = arr[i];
        int tmp;
        bool ok = false;
        for(int x : use){
            if(x == curr){
                continue;
            }
            if(B.find(x) == B.end() && (mp.find(x) == mp.end() || mp[x] < i)){
                B.insert(x);
                ans.push_back(x);
                tmp = x;
                // cout<<*itr<<"\n";
                prev = x;
                ok = true;
                break;
            }
        }
        if(!ok){
            B.insert(prev);
            ans.push_back(prev);
        }
        else{
            use.erase(tmp);
        }
    }
    for(int x : ans){
        cout<<x<<" ";
    }
    cout<<"\n";
    return 0;
}