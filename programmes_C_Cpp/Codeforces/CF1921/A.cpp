#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{int x,y;};
void solve(){
    vector<Node>a(4);
    for(int i=0;i<4;++i) cin>>a[i].x>>a[i].y;
    sort(a.begin(),a.end(),[](const Node&x,const Node&y){return x.y==y.y?x.x<y.y:x.y>y.y;});
    int l=a[1].x-a[0].x,w=a[0].y-a[2].y;
    cout<<abs(l*w)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
