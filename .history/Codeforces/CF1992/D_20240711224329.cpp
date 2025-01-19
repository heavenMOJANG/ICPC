#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(k);
    for(int i=0;i<k;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int sum=0,p=k-1;
    for(int i=0;i<k;++i)
        if(a[i]==1) sum++;
        else{p=i;break;}
    for(int i=p;i<k-1;++i) sum+=a[i]*2-1;
    cout<<sum<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}