#include<bits/stdc++.h>
 
using namespace std;
 
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(v) (int) (v).size()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
int main(){
    FAST
    int n, q;
    cin >> n >> q;
    int ans[n + 1][30];
    for(int i = 1; i <= n; i++){
        cin >> ans[i][0];
    }
    for(int i = 1; i < 30; i++){
        for(int j = 1; j <= n; j++){
            ans[j][i] = ans[ans[j][i - 1]][i - 1];
        }
    }
    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i = 29; i >= 0; i--){
            if(k & (1 << i)){
                x = ans[x][i];
            }
        }
        cout << x << '\n';
    }
    return 0;
}
