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
        int n, m, k; cin >> n >> m >> k;
        vector<int> desired(n);
        vector<int>ap(m);
        for(auto &i : desired){
            cin >> i;
        }
        for(auto &i : ap){
            cin >> i;
        }
        sort(all(desired));
        sort(all(ap));
        int ans = 0;
        for(int p1 = 0, p2 = 0; p1 < n && p2 < m;){
            if(abs(desired[p1] - ap[p2]) <= k){
                ans++;
                p1++;
                p2++;
            }
            else{
                if(ap[p2] > desired[p1]){
                    p1++;
                }
                else{
                    p2++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
