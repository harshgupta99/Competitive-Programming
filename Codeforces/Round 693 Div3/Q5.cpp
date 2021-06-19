#include<bits/stdc++.h>
using namespace std;
int binarySearch(int low, int high, vector<pair<pair<long long int, long long int>, int> > &a, long long int val){
    int ans = -1;
    while(high >= low){
        int mid = (low + high) / 2;
        if(a[mid].first.first >= val){
            high = mid - 1;
        }
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    vector<long long int> H(n), W(n);
    vector<pair<pair<long long int, long long int>, int > > a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first.first >> a[i].first.second;
        H[i] = a[i].first.first;
        W[i] = a[i].first.second;
        b[i].first.first = a[i].first.second;
        b[i].first.second = a[i].first.first;
        a[i].second = i+1;
        b[i].second = i+1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> answer(n, -1);
    vector<int> range_minA(n, 0);
    long long int miny = a[0].first.second;
    int idx = 0;
    for(int i = 1; i < n; i++){
        if(miny > a[i].first.second){
            miny = a[i].first.second;
            idx = i;
        }
        range_minA[i] = idx;
    }
    vector<int> range_minB(n, 0);
    miny = b[0].first.second;
    idx = 0;
    for(int i = 1; i < n; i++){
        if(miny > b[i].first.second){
            miny = b[i].first.second;
            idx = i;
        }
        range_minB[i] = idx;
    }
    for(int i = 0; i < n; i++){
        int lim = binarySearch(0, n-1, a, H[i]);
        if(lim != -1){
            if(a[range_minA[lim]].first.second < W[i]){
                answer[i] = a[range_minA[lim]].second;
            }
        }
        if(answer[i] == -1){
            lim = binarySearch(0, n-1, b, H[i]);
            if(lim != -1){
                if(b[range_minB[lim]].first.second < W[i]){
                    answer[i] = b[range_minB[lim]].second;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
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