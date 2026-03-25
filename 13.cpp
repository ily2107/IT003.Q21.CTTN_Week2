//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
// #define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=5e6+5;
int n,a[N];
signed main() {
    // freopen(ily2107".inp","r",stdin);
    // freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    int x;
    cin >> x;
    int l=1,r=n;
    while (l<=r){
        int d=(l+r)/2;
        if (a[d]==x){
            cout << "YES";
            return 0;
        }
        if (a[l]<=a[d]) {
            if (a[l]<=x && x<a[d]) r=d-1;
            else l=d+1;
        } else { 
            if (a[d]<x && x<=a[r]) l=d+1;
            else r=d-1;
        }
    }
    cout << "NO";
    return 0;
}