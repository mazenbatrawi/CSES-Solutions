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
#define ld long double
#define PI 3.141592653589793238
 
int main(){
    FAST
    string s; cin >> s;
    map<char,int>cnt;
    int y = s.size();
    for(int i=0; i<y; i++){
        cnt[s[i] - 'A']++;
    }
    int odd=0;
    char j;
    for(int i=0; i<26; i++){
        if(cnt[i] % 2 != 0){
            odd++;
        }
    }
    if(odd>1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    else{
            if(s.size() % 2 == 0){
                string x = "";
                for(char c='A';c<='Z';c++){
                    if(cnt[c-'A']>0){
                        for(int m=0;m<cnt[c-'A']/2;m++){
                            x+=c;
                        }
                    }
                }
                cout << x;
                reverse(x.begin(),x.end());
                cout << x << endl;
                return 0;
            }
            else{
                string x;
                for(char c='A';c<='Z';c++){
                    if(cnt[c - 'A' ] % 2 == 1){
                        j=c;
                    }
                    if(cnt[c-'A']>0){
                        for(int m=0;m<cnt[c-'A']/2;m++){
                            x+=c;
                        }
                    }
                }
                cout << x <<j;
                reverse(x.begin(),x.end());
                cout << x << endl;
                return 0;
            }
    }
    return 0;
}
