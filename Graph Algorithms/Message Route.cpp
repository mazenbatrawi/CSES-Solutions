#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = (int) v.size();
    cout << end << '\n';
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n + 1, 0);
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(int x : adj[s]){
            if(!visited[x]){
                visited[x] = 1;
                q.push(x);
                parent[x] = s;
            }
        }
    }
    if(!visited[n]){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vector<int> ans;
    int s = n;
    while(s != 1){
        ans.push_back(s);
        s = parent[s];
    }
    ans.push_back(1);
    reverse(all(ans));
    output_vector(ans);
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
