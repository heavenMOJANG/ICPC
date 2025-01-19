#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,t,p;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>t>>p;
    vector<int>l(n+1);
    for(int i=1;i<=n;++i) cin>>l[i];
    sort(l.begin()+1,l.end());
    int pos=0;
    if(l[n-p+1]<=t) cout<<t-l[n-p+1]<<"\n";
    else cout<<"0\n";
    return 0;
}