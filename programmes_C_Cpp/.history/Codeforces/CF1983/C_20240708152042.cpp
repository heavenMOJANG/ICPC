#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),b(n+1),c(n+1),preA(n+1,0),preB(n+1,0),preC(n+1,0);
    for(int i=0;i<n;++i) cin>>a[i],preA[i]=preA[i-1]+a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    for(int i=0;i<n;++i) cin>>c[i];
    int border=(preA[n]+2)/3;
    //Situation 1 ABC
    int la=1,ra=lower_bound(preA.begin()+2,preA.begin()+1+n,preA[1]+border)-preA.begin();
    if(ra==n) goto label1;
    //Situation 2 ACB
    label1:

    //Situation 3 BAC
    //Situation 4 BCA
    //Situation 5 CAB
    //Situation 6 CBA
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}