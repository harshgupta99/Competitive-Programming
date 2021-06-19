#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<pair<long long int, long long int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    vector<long long int> dist(n);
    for(int i = 0; i < n; i++){
        cin >> dist[i];
    }
    long long int answer = a[0].first + dist[0];
    long long int curr_time = a[0].first + dist[0];
    long long int prev = 0LL;
    for(int i = 0; i < n-1; i++){
        //cout << "Station " << i+1 << " Arrival: " << curr_time << " ";
        answer += (a[i].second - a[i].first + 1) / 2;
        curr_time += (a[i].second - a[i].first + 1) / 2;
        long long int more_time = max(0LL, a[i].second - curr_time);
        answer += more_time;
        curr_time += more_time;
        //cout << "Departure: " << curr_time << "\n";
        answer += a[i+1].first - a[i].second + dist[i+1];
        curr_time += a[i+1].first - a[i].second + dist[i+1];
    }
    cout << answer << "\n";
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
