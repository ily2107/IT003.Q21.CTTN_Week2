//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=1e6+5;
int n;
pair<int,int> a[N];
bool cmp(pair<int,int> x,pair<int,int> y) {
    if (x.fi==y.fi) return x.se>y.se;
    return x.fi<y.fi;
}
signed main() {
    freopen(ily2107".inp","r",stdin);
    freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;++i) cout << a[i].fi << " " <<  a[i].se << '\n';
    return 0;
}