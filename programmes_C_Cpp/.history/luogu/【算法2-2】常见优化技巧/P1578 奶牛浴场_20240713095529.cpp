#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5010;
struct Point{int x,y;}a[N];
void solve(){
    int l,w,n;cin>>l>>w>>n;
    for(int i=1;i<=n;++i) cin>>a[i].x>>a[i].y;
    a[++n]={0,0};a[++n]={0,w};
    a[++n]={l,0};a[++n]={l,w};
    sort(a+1,a+1+n,[](const Point&a,const Point&b){return a.x!=b.x?a.x<b.x:a.y<b.y;});
    int maxn=0;
    for(int i=1;i<=n;++i){
        int up=w,down=0,len=l-a[i].x;
        for(int j=i+1;j<=n;++j){
            if(len*(up-down)<=maxn) break;
            maxn=max(maxn,(a[j].x-a[i].x)*(up-down));
            if(a[j].y==a[i].y) break;
            else if(a[j].y>a[i].y) up=min(up,a[j].y);
            else down=max(down,a[j].y);
        }
        up=w,down=0,len=a[i].x;
        for(int j=i-1;j;--j){
            if(len*(up-down)<=maxn) break;
            maxn=max(maxn,(a[i].x-a[j].x)*(up-down));
            if(a[j].y==a[i].y) break;
            else if(a[j].y>a[i].y) up=min(up,a[j].y);
            else down=max(down,a[j].y);
        }
    }
    sort(a+1,a+1+n,[](const Point&a,const Point&b){return a.y<b.y;});
    for(int i=1;i<n;++i) maxn=max(maxn,n*(a[i+1].y-a[i].y));
    cout<<maxn<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}