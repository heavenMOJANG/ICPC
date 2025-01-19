#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,q,a[300010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    cin>>q;
    auto check=[&](int x,int y){
        while(x&&y){
            if((y&1)&&!(x&1)) return 1;
            x>>=1;
            y>>=1;
        }
        return 0;
    };
    while(q--){
        int x,y;cin>>x>>y;
        int ans=0;
        for(int i=1;i<=x;++i) if(check(x,i)) ans^=a[y+i];
        cout<<ans<<"\n";
    }
    return 0;
}
