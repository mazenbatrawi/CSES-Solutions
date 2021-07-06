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
 
vector<int>a;
int n, k;
 
bool ok(int mid){
    int crnt = 0, cnt = 1;
    for(int i = 0; i < n; i++){
        crnt += a[i];
        if(a[i] > mid)return 0;
        if(crnt > mid){
            crnt = a[i];
            cnt++;
        }
    }
    return cnt <= k;
}
 
int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            a.pb(x);
        }
        int lo = 0, hi = 1e16, mid;
        while(lo < hi){
            mid = (lo + hi) / 2;
            if(ok(mid)){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        cout << hi << endl;
    }
    return 0;
}
