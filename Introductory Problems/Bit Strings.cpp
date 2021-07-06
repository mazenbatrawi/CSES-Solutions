#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define l long
#define mm(arr) memset(arr, 0, sizeof(arr))
 
using namespace std;

int main(){
    FAST
    int n; cin >> n;
    int ans=2;
    for(int i = 0; i<n-1; i++){
        ans*=2;
        ans%=MOD;
    }
    cout << ans << endl;
    return 0;
 
}
