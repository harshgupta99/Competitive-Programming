#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = n; i <= 2000; i++){
        int sum = 0;
        int cpy = i;
        while(cpy> 0){
            sum += cpy%10;
            cpy /=10;
        }
        if(sum%4 == 0){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}