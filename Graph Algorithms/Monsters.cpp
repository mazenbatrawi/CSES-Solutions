#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    int x = -1, y = -1;
    queue<vector<int>> q;
    vector<vector<int>> cost_monsters(n, vector<int> (m, 1e9 + 5));
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'A'){
                x = i, y = j;
            }
            if(s[i][j] == 'M'){
                q.push({i, j, 0});
                cost_monsters[i][j] = 0;
            }
        }
    }
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    auto check = [&] (int i, int j) -> bool {
        return 0 <= min(i, j) && i < n && j < m && s[i][j] != '#';
    };
    function<vector<vector<int>>(queue<vector<int>>, vector<vector<int>>)> bfs = [&] 
            (queue<vector<int>> q, vector<vector<int>> cost) {
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            int xx = v[0], yy = v[1], crnt_cost = v[2];
            for(int i = 0; i < 4; i++){
                int nx = xx + dx[i], ny = yy + dy[i];
                if(!check(nx, ny)){
                    continue;
                }
                if(crnt_cost + 1 < cost[nx][ny]){
                    cost[nx][ny] = crnt_cost + 1;
                    q.push({nx, ny, cost[nx][ny]});
                }
            }
        }
        return cost;
    };
    cost_monsters = bfs(q, cost_monsters);
    vector<vector<int>> cost(n, vector<int> (m, 1e9 + 5));
    q.push({x, y, 0});
    cost[x][y] = 0;
    vector<vector<vector<int>>> parent(n, vector<vector<int>> (m, vector<int> (2, -1)));
    while(!q.empty()){
        vector<int> v = q.front();
        q.pop();
        int xx = v[0], yy = v[1], crnt_cost = v[2];
        for(int i = 0; i < 4; i++){
            int nx = xx + dx[i], ny = yy + dy[i];
            if(!check(nx, ny)){
                continue;
            }
            if(crnt_cost + 1 < cost_monsters[nx][ny] && crnt_cost + 1 < cost[nx][ny]){
                cost[nx][ny] = crnt_cost + 1;
                q.push({nx, ny, cost[nx][ny]});
                parent[nx][ny] = {xx, yy};
            }
        }
    }
    auto print = [&] (int xx, int yy, int sx, int sy) -> string {
        string ret = "";
        while(xx != sx || yy != sy){
            int nx = parent[xx][yy][0], ny = parent[xx][yy][1];
            if(nx - xx == 0){
                if(ny > yy){
                    ret += 'L';
                }
                else{
                    ret += 'R';
                }
            }
            else{
                if(nx > xx){
                    ret += 'U';
                }
                else{
                    ret += 'D';
                }
            }
            xx = nx, yy = ny;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    };
    for(int i = 0; i < n; i++){
        vector<int> v = {0, m - 1};
        for(int j : v){
            if(cost[i][j] != 1e9 + 5){
                string ans = print(i, j, x, y);
                cout << "YES" << '\n';
                cout << (int) ans.size() << '\n';
                cout << ans << '\n';
                return;
            }
        }
    }
    for(int j = 0; j < m; j++){
        vector<int> v = {0, n - 1};
        for(int i : v){
            if(cost[i][j] != 1e9 + 5){
                string ans = print(i, j, x, y);
                cout << "YES" << '\n';
                cout << (int) ans.size() << '\n';
                cout << ans << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
}
 
int32_t main(){
    FAST
    int tt = 1;
    while(tt--){
        solve();
    }
    return 0;
}
