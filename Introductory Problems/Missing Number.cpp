#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define l long
#define mm(arr) memset(arr, 0, sizeof(arr))
 
using namespace std;
int main()
{
    FAST;
    ll n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n-1; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n-1);
    int j=1;
    for(int i=0; i<n-1; i++)
    {
        if(j != a[i])
        {
            cout << j << endl;
            return 0;
        }
        j++;
    }
    cout << j << endl;
    return 0;
}
