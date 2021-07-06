#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
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
 
int main(){
    FAST
    int t=1;
    //cin >> t;
    while(t--){
        int n,x; cin >> n >> x;
        int a[n];
        map<int,vector<int>>pos;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]].pb(i+1);
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int sum = a[i] + a[j];
                int need = x - sum;
                if(pos.count(need)){
                    int y = pos[need].size();
                    for(int k = 0; k < min(3, y); k++){
                        if(pos[need][k] != i+1 && pos[need][k] != j+1){
                            cout << i+1 << " " << j+1 << " " << pos[need][k] << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
