//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=1e5+5;
int n,q,a[N];
signed main() {
    freopen(ily2107".inp","r",stdin);
    freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+n+1);
    while (q--) {
        int x;
        cin >> x;
        int so=lower_bound(a+1,a+n+1,x)-a;
        if (so==n+1) cout << -1 << '\n';
        else cout << a[so] << '\n';
    }
    return 0;
}