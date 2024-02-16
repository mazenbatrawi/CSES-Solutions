#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
vector<int> dij(int s, vector<pair<int, int>> *adj, int n){
    vector<int> cost(n + 1, 1e18 + 5);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(cost[p.second] != p.first) continue;
        for(auto pp : adj[p.second]){
            if(p.first + pp.second < cost[pp.first]){
                cost[pp.first] = p.first + pp.second;
                pq.push({cost[pp.first], pp.first});
            }
        }
    }
    return cost;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj1[n + 1], adj2[n + 1];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    vector<int> st = dij(1, adj1, n);
    vector<int> en = dij(n, adj2, n);
    int ans = 1e18 + 5;
    for(int i = 1; i <= n; i++){
        if(st[i] == 1e18 + 5) continue;
        for(pair<int, int> x : adj1[i]){
            if(en[x.first] == 1e18 + 5) continue;
            ans = min(ans, st[i] + en[x.first] + x.second / 2);
        }
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
