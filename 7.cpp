//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define ily2107 "ily2107"
#define pi pair<string,int>
#define time (1.0*clock()/CLOCKS_PER_SEC)
const int N=1e5+5;
int n;
string a[N];
pi gia[N];
vector<pi> vec;
void merge(int l,int d,int r) {
    int i=l,j=d+1;
    int k=0;
    while (i<=d && j<=r) {
        string cap;
        if (a[i]<a[j]) cap=a[i++];
        else cap=a[j++]; 
        gia[k++].fi=cap;
    }
    while (i<=d) gia[k++].fi=a[i++];
    while (j<=r) gia[k++].fi=a[j++];
    for (int i=0;i<k;++i) a[l+i]=gia[i].fi;
}
void mesrt(int l,int r) {
    if (l>=r) return;
    int d=(l+r)>>1;
    mesrt(l,d);
    mesrt(d+1,r);
    merge(l,d,r);
}
bool cmp(pi x,pi y) {
    if (x.se==y.se) {
        if (x.fi.size()!=y.fi.size()) return x.fi.size()<y.fi.size();
        return x.fi<y.fi;
    }
    return x.se>y.se;
}
void merge2(int l,int d,int r) {
    int i=l,j=d+1;
    int k=0;
    while (i<=d && j<=r) {
        pi cap;
        if (cmp(vec[i],vec[j])) cap=vec[i++];
        else cap=vec[j++]; 
        gia[k++]=cap;
    }
    while (i<=d) gia[k++]=vec[i++];
    while (j<=r) gia[k++]=vec[j++];
    for (int i=0;i<k;++i) vec[l+i]=gia[i];
}
void mesrt2(int l,int r) {
    if (l>=r) return;
    int d=(l+r)>>1;
    mesrt2(l,d);
    mesrt2(d+1,r);
    merge2(l,d,r);
}
signed main() {
    freopen(ily2107".inp","r",stdin);
    freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0); 
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    mesrt(1,n);
    for (int i=1;i<=n;++i) {
        int cnt=1;
        while (i<n && a[i]==a[i+1]) ++i,++cnt;
        vec.push_back({a[i],cnt});
    }
    int so=vec.size();
    mesrt2(0,so-1);
    for (auto x:vec) cout << x.fi << " " << x.se << '\n';
    return 0;
}