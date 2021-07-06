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
 
int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int>a(n);
        for(auto &i : a)cin >> i;
        int lo = 0, hi = 1e18 + 5, mid;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            int ans = 0;
            for(auto i : a){
                ans += mid / i;
                if(ans >= k)break;
            }
            if(ans >= k){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        cout << lo << endl;
    }
    return 0;
}
