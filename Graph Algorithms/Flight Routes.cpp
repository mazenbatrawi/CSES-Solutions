#include<bits/stdc++.h>
 
using namespace std;
#define int long long
 
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int) v.size();
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<int> cost[n + 1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[1].push(0LL);
    pq.push({0LL, 1});
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        long long crnt = p.first;
        if(crnt > cost[node].top()){
            continue;
        }
        for(auto x : adj[node]){
            int ncost = crnt + x.second;
            int nnode = x.first;
            if((int) cost[nnode].size() < k){
                cost[nnode].push(ncost);
                pq.push({ncost, nnode});
            }
            else if(ncost < cost[nnode].top()){
                cost[nnode].pop();
                cost[nnode].push(ncost);
                pq.push({ncost, nnode});
            }
        }
    }
    vector<int> ans;
    assert((int) cost[n].size() == k);
    while((int) cost[n].size()){
        ans.push_back(cost[n].top());
        cost[n].pop();
    }
    reverse(ans.begin(), ans.end());
    output_vector(ans);
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
