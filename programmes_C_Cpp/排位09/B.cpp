#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int idx;
void solve(){
    cout<<"Case "<<++idx<<":\n";
    int m,n;cin>>m>>n;
    int minn=LLONG_MAX,p=2;
    while(m!=1){
        int km=0;
        while(m%p==0) m/=p,km++;
        if(km){
            int tmp=n,kn=0;
            while(tmp) kn+=tmp/p,tmp/=p;
            minn=min(minn,kn/km);
        }
        p++;
    }
    cout<<(minn?to_string(minn):"Impossible to divide")<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
