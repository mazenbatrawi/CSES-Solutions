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
 
int fastpow(int v, int p){
    if (p == 0)return 1;
    if (p == 1)return v;
    int ans = fastpow(v, p/2);
    if (p&1)return (((ans%MOD) * (ans%MOD)%MOD) * (v%MOD))%MOD;
    else return ((ans%MOD) * (ans%MOD))%MOD;
}
 
int32_t main(){
    FAST
    int t=1;
    cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        cout << fastpow(a,b) << endl;
    }
    return 0;
}
