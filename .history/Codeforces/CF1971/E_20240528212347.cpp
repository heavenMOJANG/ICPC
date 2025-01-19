#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k,q;cin>>n>>k>>q;
    vector<int>a(k+1,0),b(k+1,0);
    for(int i=1;i<=k;++i) cin>>a[i];
    for(int i=1;i<=k;++i) cin>>b[i];
    while(q--){
        int x;cin>>x;
        if(x==0){cout<<"0 ";continue;}
        int p=upper_bound(a.begin(),a.begin()+1+k,x)-a.begin()-1;
        int d=x-a[p-1];
        int tmp=d*(b[p]-b[p-1])/(a[p]-a[p-1]);
        cout<<tmp+b[p-1]<<" ";
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}