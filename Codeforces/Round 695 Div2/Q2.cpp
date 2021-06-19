#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n < 3){
        puts("0");
        return;
    }
    int cnt = 0;
    vector<bool> hill(n, false);
    vector<bool> valley(n, false);
    for(int i = 1; i < n-1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]){
            ++cnt;
            hill[i] = true;
        }
        if(a[i] < a[i-1] && a[i] < a[i+1]){
            ++cnt;
            valley[i] = true;
        }
    }
    if(cnt <= 1){
        puts("0");
        return;
    }
    // HHH -> NO
    // VVV -> NO
    // HHV -> NO
    // VHH -> NO
    // HVV -> NO
    // VVH -> NO
    // H.H -> NO
    // V.V -> NO
    // H.V -> 2 8 6 4 8
    // V.H -> done

    // HV. -> 2 5 3 1 2 -> num >= 5
    // VH. -> 4 3 5 4 2
    // .HV ->
    // .VH -> 
    // HVH -> 4 2 3
    // VHV -> 6 4 3 3 8
    int tmp = 1;
    for(int i = 1; i < n-1; i++){
        if(hill[i-1] && valley[i] && hill[i+1]){
            cout << cnt - 3 << "\n";
            return;
        }
        else if(valley[i-1] && hill[i] && valley[i+1]){
            cout << cnt - 3 << "\n";
            return;
        }
        else if((hill[i-1] && valley[i+1]) || (valley[i-1] && hill[i+1])){
            ;
        }
        else if(hill[i-1] && valley[i]){
            if(i+1 <= n-2){
                // consider a[i] = a[i-1]
                int x = a[i-1];
                int y = a[i+1];
                int z = a[i+2];
                if(y < x && y < z){
                    ;
                }
                else if(y > x && y > z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
                x = a[i+1];
                y = a[i-1];
                z = a[i-2];
                if(y > x && y > z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
            }
            else{
                tmp = max(tmp, 2);
            }
        }
        else if(valley[i-1] && hill[i]){
            if(i+1 <= n-2){
                // consider a[i] = a[i-1]
                int x = a[i-1];
                int y = a[i+1];
                int z = a[i+2];
                if(y < x && y < z){
                    ;
                }
                else if(y > x && y > z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
                x = a[i+1];
                y = a[i-1];
                z = a[i-2];
                if(y < x && y < z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
            }
            else{
                tmp = max(tmp, 2);
            }
        }
        else if(hill[i+1] && valley[i]){
            if(i-1 >= 1){
                // consider a[i] = a[i+1]
                int x = a[i+1];
                int y = a[i-1];
                int z = a[i-2];
                if(y < x && y < z){
                    ;
                }
                else if(y > x && y > z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
                x = a[i-1];
                y = a[i+1];
                z = a[i+2];
                if(y > x && y > z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
            }
            else{
                tmp = max(tmp, 2);
            }
        }
        else if(hill[i] && valley[i+1]){
            if(i-1 >= 1){
                // consider a[i] = a[i+1]
                int x = a[i+1];
                int y = a[i-1];
                int z = a[i-2];
                if(y < x && y < z){
                    ;
                }
                else if(y > x && y > z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
                x = a[i-1];
                y = a[i+1];
                z = a[i+2];
                if(y < x && y < z){
                    ;
                }
                else{
                    tmp = max(tmp, 2);
                }
            }
            else{
                tmp = max(tmp, 2);
            }
        }
    }
    cout << cnt - tmp << "\n";
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}