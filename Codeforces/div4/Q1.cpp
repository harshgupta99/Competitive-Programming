//https://codeforces.com/gym/102873/problem/0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<bool> done(n+1);
    for(int i = 0; i < k; i++){
        cin >> a[i];
        done[a[i]] = true;
    }
    int imp = -1;
    for(int i = 1; i <= n; i++){
        if(!done[i]){
            if(imp == -1){
                imp = i;
            }
            else{
                puts("NO");
                return 0;
            }
        }
    }
    if(imp == -1){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}