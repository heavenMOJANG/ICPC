#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll T,n;
ll sg(ll a,ll b){
    ll cnt=0;
    while(1){
        if(a&1&&b&1) return cnt;
        if(a&1) a++;
        else if(b&1) b++;
        else a>>=1,b>>=1,cnt++;
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ll res=0;
        cin>>n;
        for(ll i=1,a,b;i<=n/2;++i) cin>>a>>b,res^=sg(a,b);
        cout<<(res?"YES\n":"NO\n");
    }
    return 0;
}
