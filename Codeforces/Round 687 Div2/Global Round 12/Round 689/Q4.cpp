//https://codeforces.com/contest/1461/problem/D
#include<bits/stdc++.h>
using namespace std;
set<long long int> st;
vector<long long int> a, pref;
int binarySearch(int M, int low, int high){
    int answer = -1;
    while(high >= low){
        int mid = (low + high)/2;
        if(a[mid] <= M){
            answer = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return answer;
}
void pre(int lpointer, int rpointer){
    long long int tmp = 0;
    if(lpointer > rpointer){
        //puts("BGB");
        return;
    }
    if(lpointer){
        tmp = pref[lpointer-1];
    }
    st.insert(pref[rpointer] - tmp);
    if(lpointer == rpointer){
        //puts("YES");
        return;
    }
    long long int mid = (a[lpointer] + a[rpointer])/2;
    if(a[lpointer] > mid || a[rpointer] <= mid){
        return;
    }
    int pt = binarySearch(mid, lpointer, rpointer);
    // cout << mid << "\n";
    // cout << pt << "\n";
    //return;
    // check if left and right extension exist
    pre(lpointer, pt);
    pre(pt+1, rpointer);
}
void solve(){
    int n, q;
    cin >> n >> q;
    a.resize(n);
    pref.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        if(i){
            pref[i] = pref[i-1] + a[i];
        }
        else{
            pref[i] = a[i];
        }
    }
    st.clear();
    pre(0, n-1);
    while(q--){
        long long int k;
        cin >> k;
        if(st.find(k) != st.end()){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}