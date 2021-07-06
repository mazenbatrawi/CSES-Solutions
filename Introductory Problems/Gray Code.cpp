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
 
const int N = 17;
vector<int>adj[(1<<N)];
bool visited[(1<<N)];
int n;
 
string tobin(int x){
    string s = "";
    for(int i=0;i<n;i++){
        if(x&(1<<i)){
            s+='1';
        }
        else{
            s+='0';
        }
    }
    reverse(all(s));
    return s;
}
void dfs(int s){
    if(!visited[s]){
        visited[s] = 1;
        cout << tobin(s) << endl;
        for(int i=0;i<adj[s].size();i++){
            dfs(adj[s][i]);
        }
    }
}
int32_t main(){
    FAST
    int t=1;
    //cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i < (1<<n); i++){
            for(int j = 0;j<n;j++){
                if(i&(1<<j)){
                    adj[i].pb(i - (1<<j));
                }
                else{
                    adj[i].pb(i + (1<<j));
                }
            }
        }
        dfs(0);
    }
    return 0;
}
