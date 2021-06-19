#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        long long int k;
        cin >> k;
        k--;
        long long last = 0;
        long long int nxt = 1;
        int len = 0;
        for(long long int i = 1; ; i++){
            if(i == nxt){
                ++len;
                nxt *= 10;
            }
            last += len;
            if(k >= last){
                k -= last;
            }
            else{
                long long int nxt = 1;
                int len = 0;
                for(long long int j = 1; j <= i; j++){
                    if(j == nxt){
                        len++;
                        nxt *= 10;
                    }
                    if(k >= len){
                        k -= len;
                    }
                    else{
                        cout << to_string(j)[k] << "\n";
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}   