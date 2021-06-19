#include<bits/stdc++.h>
using namespace std;
bool partition (vector<long long int> &arr, int n){
	long long int sum = 0;
	int i, j;
	for (i = 0; i < n; i++)
	sum += arr[i];

	if (sum % 2 != 0)
	return false;

	bool part[n + 1][sum / 2 + 1];
	for (i = 0; i <= sum/2; i++)
        part[0][i] = false;

	for (i = 0; i <= n; i++)
	part[i][0] = true;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= sum/2; j++)
		{
			part[i][j] = part[i-1][j];
			if (j >= arr[i - 1])
			part[i][j] = part[i][j] ||
						part[i - 1][j - arr[i -1]];

		}
	}
	return part[n][sum/2];
}
void solve(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    bool odd = false;
    long long int sum = 0LL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        odd |= (a[i]&1LL);
        sum += a[i];
    }
    if(sum & 1LL){
        cout << "0\n";
        return;
    }
    if(!partition(a, n)){
        cout << "0\n";
        return;
    }
    if(odd){
        for(int i = 0; i < n; i++){
            if(a[i]&1LL){
                cout << "1\n";
                cout << i+1 << "\n";
                return;
            }
        }
    }
    vector<long long int> X;
    for(int i = 0; i < n; i++){
        X.clear();
        for(int j = 0; j < i; j++){
            X.push_back(a[j]);
        }
        for(int j = i+1; j < n; j++){
            X.push_back(a[j]);
        }
        if(!partition(X, n-1)){
            cout << "1\n" << i+1 << "\n";
            return;
        }
    }
    assert(false);

    // if sum is odd then answer is 0
    // if sum is even and minimum difference is 0, then:
    // check if there exists an odd number, then the answer is 1
    // 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--){
        solve();
    }
}