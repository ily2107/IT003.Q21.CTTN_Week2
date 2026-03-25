//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
// #define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=1e7;
int n,sz,bit[N];
pair<int,int> a[N];
vector<int> vec;
void update(int p,int val){
    for(;p<=sz;p+=p&-p) bit[p]+=val;
}
int get(int p){
    int sum=0;
    for(;p>0;p-=p&-p) sum+=bit[p];
    return sum;
}
signed main() {
    freopen(ily2107".inp","r",stdin);
    freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while (cin >> a[++n].fi) {
        if (a[n].fi==0) {
            --n;
            break;
        }
        cin >> a[n].se;
    }
    for (int i=1;i<=n;++i) vec.push_back(a[i].se);
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
    sz=vec.size();
    for (int i=1;i<=n;++i) {
        int cnt=lower_bound(vec.begin(),vec.end(),a[i].se)-vec.begin();
        ++cnt;
        if (a[i].fi==1) {
            if (get(cnt)-get(cnt-1)==0) update(cnt,1);
        } else {
            if (get(cnt)-get(cnt-1)) {
                int so=get(cnt-1);
                cout << so+1 << '\n';
            } else cout << 0 << '\n';
        }
    }
    return 0;
}