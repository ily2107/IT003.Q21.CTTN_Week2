//Created by Vũ Thị Thu Hường
const int N=1e5+5;
int n,k,ans,a[N],temp[N];
void merge(int l,int d,int r) {
    int i=l,j=d+1;
    int k=0;
    while (i<=d && j<=r) {
        int cap;
        if (a[i]<a[j]) cap=a[i++];
        else cap=a[j++]; 
        temp[k++]=cap;
    }
    while (i<=d) temp[k++]=a[i++];
    while (j<=r) temp[k++]=a[j++];
    for (int i=0;i<k;++i) a[l+i]=temp[i];
}
void mesrt(int l,int r) {
    if (l>=r) return;
    int d=(l+r)>>1;
    mesrt(l,d);
    mesrt(d+1,r);
    merge(l,d,r);
}
signed main() {
    // freopen(ily2107".inp","r",stdin);
    // freopen(ily2107".out","w",stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i];
    mesrt(1,n);
    int l=1,r=n;
    while (l<r) {
        if (a[l]+a[r]<=k) {
            if (a[l]+a[r]>ans) ans=a[l]+a[r];
            ++l;
        } else --r;
    }
    cout << ans;
    return 0;
}
