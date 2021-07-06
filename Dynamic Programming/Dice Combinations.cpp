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
 
const int N = 1e6 + 5;
int dp[N];
int n;
 
int calc(int sum){
    if(sum == n){
        return 1;
    }
    if(sum>n){
        return 0;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }
    int ret = 0;
    for(int i = 1; i <= 6; i++){
        ret += calc(sum+i);
        ret %= MOD;
    }
    return dp[sum] = ret;
}
 
int32_t main(){
    FAST
    int t=1;
    //cin >> t;
    while(t--){
        cin >> n;
        memset(dp,-1,sizeof(dp));
        cout << calc(0) << endl;
    }
    return 0;
}
