#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define int int64_t
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define coutArray(a,n) for(int i = 0; i < n; i++){cout << a[i] << " ";};cout << endl;
#define ld long double
#define PI 3.141592653589793238
#define all(v) v.begin(), v.end()
 
const int N = 1005;
string s[N];
bool visited[N][N];
int n,m;
 
void dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m)return;
    if(s[i][j] == '#' || visited[i][j])return;
    visited[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}
 
int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && s[i][j] != '#'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
