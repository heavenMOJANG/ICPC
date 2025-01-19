#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
class Solution{
public:
    ll T,n,m,t[200010];
    ll lowbit(ll x){return x&(-x);}
    ll sum(ll x){
        ll res=0;
        while(x) res+=t[x],x-=lowbit(x);
        return res;
    }
    void main(){
        cin>>T;
        while(T--){
            cin>>n>>m;
            for(ll i=1;i<=n;++i) cin>>t[i];
            for(ll i=1,op,l,r;i<=m;++i){
                cin>>op>>l>>r;
                if(op==1){
                    ll x;cin>>x;
                    for(ll j=l;j<=r;++j) t[i]=abs(t[i]-x);
                }
                else cout<<sum(r)-sum(l-1)<<"\n";
            }
        }
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}
