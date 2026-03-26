//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
// #define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=5e5+5;
int n,k,kq,ma,a[N];
signed main() {
    // freopen(ily2107".inp","r",stdin);
    // freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i],ma=max(ma,a[i]);
    int l=ma,r=1e9;
    while(l<=r){
        int d=(l+r)>>1;
        int sum=0,cnt=0;
        for (int i=1;i<=n;++i) {
            if (sum+a[i]>d) {
                ++cnt;
                sum=a[i];
            } else sum+=a[i];
        }
        if (sum) ++cnt;
        if (cnt<=k) r=d-1,kq=d;
        else l=d+1;
    }
    cout << kq;
    return 0;
}
