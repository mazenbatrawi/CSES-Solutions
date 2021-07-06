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
    int t=1;
    //cin >> t;
    while(t--){
        int n; cin >> n;
        set<int>s;
        for(int i = 0; i < n; i++){
            s.insert(i+1);
        }
        auto it = s.begin();
        it++;
        while(!s.empty()){
            if(it == s.end()) it = s.begin();
            auto it2 = it;
            cout << *it << " ";
            it2++;
            if(it2 == s.end()) it2 = s.begin();
            s.erase(*it);
            it2++;
            it = it2;
        }
    }
    return 0;
}
