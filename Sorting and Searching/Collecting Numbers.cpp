#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define inF freopen("input.txt", "r", stdin);
#define outF freopen("output.txt", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define coutArray(a,n) for(int i = 0; i < n; i++){cout << a[i] << " ";}cout << endl;
#define ld long double
#define PI 3.141592653589793238
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define int ll
 
void solve(){
    int n; cin >> n;
    vector<int> pos(n + 1, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for(int i = 2; i <= n; i++){
        ans += pos[i] < pos[i - 1];
    }
    cout << ans << endl;
}
 
int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
