#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define int int64_t
#define rep(n) for(ll i=0;i<n;i++)
#define rrep(n) for(ll i=n-1;i>=0;i--)
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
#define srt(v) sort(v.begin(),v.end())
#define all(v) v.begin(), v.end()
 
int32_t main(){
 
    int t=1;
    //cin >> t;
    while(t--){
        int n; cin >> n;
        int x = n*(n+1)/2;
        if(x&1){
            cout << "NO" << endl;
            continue;
        }
        vector<int>v(n);
        cout << "YES" << endl;
        int a[n];
        mm(a);
        v[0] = 0;
        for(int i=1;i<=n;i++){
            a[i-1] = i;
            v[i] = v[i-1]+i;
        }
        int ind = upper_bound(all(v),x/2) - v.begin();
        int left = ind*(ind+1)/2;
        int right = x - left;
        int need = left - right;
        need/=2;
        vector<int>v1,v2;
        for(int i=1;i<=ind;i++){
            if(i==need)continue;
            v1.pb(i);
 
        }
        v2.pb(need);
        for(int i = ind+1;i<=n;i++){
            v2.pb(i);
        }
        cout << v1.size() << endl;
        coutArray(v1,v1.size());
        cout << v2.size() << endl;
        coutArray(v2,v2.size());
    }
    return 0;
}
