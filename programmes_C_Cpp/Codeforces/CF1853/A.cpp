#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,a[510],ans;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>_;
    while(_--){
        cin>>n;
        ll flag=1;
        ans=0x7fffffff;
        for(ll i=1;i<=n;++i) cin>>a[i];
        for(ll i=1;i<n;++i){
            if(a[i]>a[i+1]){flag=0;break;}
            ans=min(ans,a[i+1]-a[i]);
        }
        cout<<(flag?ans/2+1:0LL)<<"\n";
    }
    return 0;
}
