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
 
const int N = 1e3 + 5;
int dp[N][N];
string s[N];
int n;
 
int calc(int i, int j){
    if(i == 0 && j == 0){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ret = 0;
    if(i - 1 > -1 && s[i - 1][j] != '*'){
        ret += calc(i - 1, j);
    }
    if(j - 1 > -1 && s[i][j - 1] != '*'){
        ret += calc(i, j - 1);
    }
    ret %= MOD;
    return dp[i][j] = ret;
}
 
int32_t main(){
    FAST
    int t=1;
    //cin >> t;
    while(t--){
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        if(s[n - 1][n - 1] == '*'){
            cout << 0 << endl;
            return 0;
        }
        cout << calc(n - 1, n - 1);
    }
    return 0;
}
