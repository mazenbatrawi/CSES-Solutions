#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007
using namespace std;
int main(){
    FAST
    int n; cin >> n;
    ll a[n];
    scanArray(a,n);
    ll cnt =0;
    for(int i=0;i<n;i++){
            if(i==n-1){
                break;
            }
            if(a[i]>a[i+1]){
                cnt+=abs(a[i]-a[i+1]);
                a[i+1]+=abs(a[i]-a[i+1]);
            }
            else{
                continue;
            }
    }
    cout << cnt << endl;
    return 0;
}
