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
 
const int N = 1e6 + 5;
int dp[N];
int n;
 
int calc(int sum){
    if(sum == 0){
        return 0;
    }
    if(sum < 0){
        return 1e9 + 5;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }
    int ret = 1e9 + 5;
    int x = sum;
    while(x){
        if(x % 10 != 0)
            ret = min(ret, calc(sum - x % 10) + 1);
        x /= 10;
    }
    return dp[sum] = ret;
}
 
int32_t main(){
    FAST
    int t = 1;
    //cin >> t;
    while(t--){
        cin >> n;
        memset(dp, -1, sizeof(dp));
        cout << calc(n) << endl;
    }
    return 0;
}
