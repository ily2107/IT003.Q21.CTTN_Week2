//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=1e5+5;
int n,m,ans,a[N],b[N];
vector<pair<int,int>> cur,vec;
bool cry(int need) {
    int j=1;
    for (int i=1;i<=n;++i) {
        if (a[i]>=need) continue;
        while (j<=m && b[i]<need-a[j]) ++j;
        if (j>m) return false;
        cur.push_back({i,j});
        ++j;
    }
    return true;
}
signed main() {
    freopen(ily2107".inp","r",stdin);
    freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    cin >> m;
    for (int i=1;i<=m;++i) cin >> b[i];
    int l=1,r=1e9;
    while (l<=r) {
        int d=(l+r)>>1;
        if (cry(d)) {
            ans=d;
            vec=cur;
            l=d+1;
        } else r=d-1;
        cur.clear();
    }
    cout << ans << " " << vec.size() << '\n';
    for (auto x:vec) cout << x.fi << " " << x.se << '\n';
    return 0;
}