#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define coutArray(a,n) for(int i = 0; i < n; i++){cout << a[i] << " ";};cout << endl;
 
 
int main(){
    FAST
    int n, m; cin >> n >> m;
    set<int> s;
    map<int, int> cnt;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.insert(x);
        cnt[x]++;
    }
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        auto index = s.upper_bound(a);
        if(index == s.begin()){
            cout << -1 << endl;
            continue;
        }
        index--;
        cout << *index << endl;
        cnt[*index]--;
        if(cnt[*index] == 0){
            s.erase(*index);
        }
    }
    return 0;
}
