#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > dur(n);
    for(int i =0; i < n;i++){
        cin >> dur[i].first;
        dur[i].second = i;
    }
    long long int shots = 0;
    int count = 0;
    sort(dur.begin(), dur.end(), greater<pair<int, int> >());
    for(int i =0; i < n; i++){
        shots += (count*dur[i].first + 1);
        count++;
    }
    cout<<shots<<"\n";
    for(int i =0; i < n; i++){
        cout<<dur[i].second + 1<<" ";
    }
    cout<<"\n";
    return 0;
}