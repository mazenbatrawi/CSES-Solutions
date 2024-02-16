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
    for(auto &S : s){
        cin >> S;
    }
    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'A'){
                sx = i, sy = j;
            }
            if(s[i][j] == 'B'){
                ex = i, ey = j;
            }
        }
    }
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<vector<bool>> visited(n, vector<bool> (m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    auto check = [&] (int i, int j) -> bool {
        return 0 <= min(i, j) && i < n && j < m && !visited[i][j] && s[i][j] != '#';
    };
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for(int a = 0; a < 4; a++){
            int nx = x + dx[a], ny = y + dy[a];
            if(check(nx, ny)){
                visited[nx][ny] = 1;
                q.push({nx, ny});
                parent[nx][ny] = {x, y};
            }
        }
    }
    if(!visited[ex][ey]){
        cout << "NO" << '\n';
        return;
    }
    string ans = "";
    while(ex != sx || ey != sy){
        int x = parent[ex][ey].first, y = parent[ex][ey].second;
        if(x == ex){
            if(ey > y){
                ans += 'R';
            }
            else{
                ans += 'L';
            }
        }
        else{
            if(ex > x){
                ans += 'D';
            }
            else{
                ans += 'U';
            }
        }
        ex = x, ey = y;
    }
    reverse(all(ans));
    cout << "YES" << '\n';
    cout << sz(ans) << '\n';
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
