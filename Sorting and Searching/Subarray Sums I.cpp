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
    int n, x; cin >> n >> x;
    int a[n];
    scanArray(a, n);
    int p1 = 0, p2 = 0;
    int ans = 0, sum = 0, ok = 1;
    while(p2 != n && p1 != n){
        sum += a[p2] * (ok);
        ok = 0;
        if(sum == x){
            ans++;
            sum -= a[p1];
            p1++;
            p2++;
            ok = 1;
        }
        else if(sum > x){
            sum -= a[p1];
            p1++;
            ok = 0;
        }
        else{
            ok = 1;
            p2++;
        }
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
