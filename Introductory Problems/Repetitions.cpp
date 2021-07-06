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
    string s; cin >> s;
    map <char,int> mp;
    int ans=0;
    int cnt;
    for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            ans=max(ans,mp[s[i]]);
            cnt=mp[s[i]];
            mp.clear();
            mp[s[i]] = cnt;
 
    }
    cout << ans << endl;
 
    return 0;
}
