#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> dp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()){
            dp.push_back(x);
        }
        else{
            *it = x;
        }
    }
    cout << (int) dp.size() << '\n';
}
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
