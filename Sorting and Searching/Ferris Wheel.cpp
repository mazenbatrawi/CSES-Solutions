#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define coutArray(a,n) for(int i = 0; i < n; i++){cout << a[i] << " ";};cout << endl;
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007
 
using namespace std;
int main(){
    FAST
    int n,x; cin >> n >> x;
    int a[n];
    scanArray(a,n);
    sort(a,a+n);
    //coutArray(a,n);
    int ans=0;
    for(int i=0,j=n-1;i<j;i++){
        while(i<j && a[i]+a[j]>x){
            j--;
        }
        if(j>i){
            ans++;
            j--;
        }
    }
    cout << n-ans;
    return 0;
}
