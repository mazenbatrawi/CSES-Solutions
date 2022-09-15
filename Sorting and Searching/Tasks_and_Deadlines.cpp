#include<bits/stdc++.h>

using namespace std;

#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

void solve(){
    int n;
    cin >> n;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    int ans = 0;
    int t = 0;
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();
        int f = t + v[0];
        int d = v[1];
        ans += d - f;
        t = f;
    }
    cout << ans << '\n';
}

int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}