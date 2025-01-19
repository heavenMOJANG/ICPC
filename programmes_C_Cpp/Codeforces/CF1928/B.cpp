#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    set<int>s;
    for(int i=0,x;i<n;++i) cin>>x,s.insert(x);
    vector<int>a;
    for(auto e:s) a.push_back(e);
    int maxn=1,sum=1,l=0;
    for(int r=1;r<a.size();r++){
        if(a[r]-a[l]>=n){
            maxn=max(maxn,sum);
            while(l<r&&a[r]-a[l]>=n) l++;
            sum=r-l+1;
        }
        else sum++;
    }
    cout<<max(maxn,sum)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
