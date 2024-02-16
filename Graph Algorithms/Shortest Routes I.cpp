#include<bits/stdc++.h>
 
using namespace std;
 
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int) v.size();
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> cost(n + 1, 1e18 + 5);
    vector<bool> visited(n + 1, 0);
    cost[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(cost[p.second] != p.first) continue;
        visited[p.second] = 1;
        for(auto node : adj[p.second]){
            long long ncost = node[1] + p.first;
            if(ncost < cost[node[0]]){
                cost[node[0]] = ncost;
                pq.push({ncost, node[0]});
            }
        }
    }
    output_vector(cost, 0, 1);
}
 
int main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
