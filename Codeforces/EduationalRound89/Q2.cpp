#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, x, m;
    cin >> n >> x >> m;
    long long int answer = 0;
    int l,r;
    int left_anchor = x;
    int right_anchor = x;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        // start processing the queries after they have 
        if(l > right_anchor || r < left_anchor){
            continue;
        }
        if(left_anchor >= l && right_anchor <= r){
            left_anchor = l;
            right_anchor = r;
            // cout<<left_anchor<<" "<<right_anchor<<"\n";
        }
        else if(left_anchor >= l && r >= left_anchor){
            left_anchor = min(left_anchor, l);
        }
        else if(right_anchor >= l && right_anchor <= r){
            right_anchor = max(r, right_anchor);
        }
    }
    cout<<right_anchor - left_anchor + 1<<"\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}