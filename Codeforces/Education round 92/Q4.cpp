#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    long long int n, k;
    cin >> n >> k;
    long long int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long long int answer = 1e18;
    // check for intersection
    if(max(l1, l2) <= min(r1, r2)){
        // they already intersect so first make them equal
        long long int rem = max(0ll, k - n * (min(r1, r2) - max(l1, l2)));
        long long int maximum_possible = n * (abs(l1 - l2) + abs(r1 - r2));
        answer = min(rem, maximum_possible) + max(0ll, rem - maximum_possible)*2;
    }
    else{
        // they do not intersect so first spend some to make them touch
        long long int invest = max(l1, l2) - min(r1, r2);
        for(long long int i = 1; i <= n; i++){
            long long int curr_answer = i * invest;
            long long int maximum_possible = i * (max(r1, r2) - min(l1, l2));
            curr_answer += min(k, maximum_possible) + max(0ll, k - maximum_possible) * 2;
            answer = min(answer, curr_answer);
        }
    }
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