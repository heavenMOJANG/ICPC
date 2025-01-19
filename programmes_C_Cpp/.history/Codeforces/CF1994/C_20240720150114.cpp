#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int i=0,j=0,sum=a[0],cnt=0;
    while(j<n){
        if(sum>=x){
            if(sum==x) cnt++;
            sum-=a[i];
            i++;
            if(i>j) sum=a[i],j++,cnt++;
        }
        if(sum<x) sum+=a[j],j++,cnt++;
    }
    cout<<cnt<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}