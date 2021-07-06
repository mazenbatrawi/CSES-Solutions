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
    ll n; cin >> n;
    cout << n << " ";
    while(n != 1){
        if(n%2 == 0){
            n/=2;
            cout << n << " ";
        }
        else{
            n=(n*3)+1;
            cout << n << " ";
        }
    }
    return 0;
}
