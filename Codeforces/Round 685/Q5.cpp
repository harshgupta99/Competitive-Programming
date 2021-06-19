#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int bits = log2(n);
    bits++;
    vector<int> answer(n+1);
    vector<int> xory(n+1);
    cout << "AND 1 2\n";
    fflush(stdout);
    int andab;
    cin >> andab;
    cout << "XOR 1 2\n";
    fflush(stdout);
    int xorab;
    cin >> xorab;
    cout << "AND 2 3\n";
    fflush(stdout);
    int andbc;
    cin >> andbc;
    cout << "XOR 2 3\n";
    fflush(stdout);
    int xorbc;
    cin >> xorbc;
    int sumab = xorab + 2*andab;
    int sumbc = xorbc + 2*andbc;
    int xorac = (xorab ^ xorbc);
    int andac = (andab & andbc);
    int sumac = xorac + 2*andac;
    xory[2] = xorab;
    xory[3] = xorac;
    answer[1] = (sumab + sumbc - sumac)/2;
    answer[2] = answer[1]^xory[2];
    answer[3] = answer[1]^xory[3];
    for(int i = 4; i <= n; i++){
        cout << "XOR 1 " << i << "\n";
        fflush(stdout);
        int x;
        cin >> x;
        answer[i] = (x ^ answer[1]);
    }
    cout << "! ";
    fflush(stdout);
    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
    return 0;
}