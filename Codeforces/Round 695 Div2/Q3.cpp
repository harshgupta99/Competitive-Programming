#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    multiset<long long int> A, B, C;
    for(int i = 0; i < n1; i++){
        long long int x;
        cin >> x;
        A.insert(x);
    }
    for(int i = 0; i < n2; i++){
        long long int x;
        cin >> x;
        B.insert(x);
    }
    for(int i = 0; i < n3; i++){
        long long int x;
        cin >> x;
        C.insert(x);
    }
    long long int answer = 0LL;
    if(*A.begin() <= *B.begin() && *A.begin() <= *C.begin()){
        if(n1 == 1){
            // make this the only hub
            long long int x = *A.begin();
            while(B.size() != 0){
                answer += B.begin();
                B.erase(B.begin());
            }
            while(C.size() != 0){
                answer += C.begin();
                C.erase(C.begin());
            }
            answer -= x;
        }
        else{
            if(*B.begin() <= *C.begin()){
                // make B the second hub
                
            }
            else{
                // make C the second hub
            }
        }
    }
    if(*B.begin() <= *A.begin() && *B.begin() <= *C.begin()){
        if(n2 == 1){
            // make this the only hub
            long long int x = *B.begin();
            while(A.size() != 0){
                answer += A.begin();
                A.erase(A.begin());
            }
            while(C.size() != 0){
                answer += C.begin();
                C.erase(C.begin());
            }
            answer -= x;
        }
        else{
            if(*A.begin() <= *C.begin()){
                // make A the second hub

            }
            else{
                // make C the second hub
            }
        }
    }
    // 5 + 6 + 5 + 4 - 1 -2 + 3
    if(*C.begin() <= *B.begin() && *C.begin() <= *A.begin()){
        if(n3 == 1){
            // make this the only hub
            long long int x = *C.begin();
            while(B.size() != 0){
                answer += B.begin();
                B.erase(B.begin());
            }
            while(A.size() != 0){
                answer += A.begin();
                A.erase(A.begin());
            }
            answer -= x;
        }
        else{
            if(*A.begin() <= *B.begin()){
                // make A the second hub

            }
            else{
                // make B the second hub
            }
        }
    }
    cout << answer << "\n";
    return;
    // 
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}