#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    k<<=1;
    vector<int>a(2*n),n1(n+1),n2(n+1),a1,a2;
    for(int i=0;i<2*n;++i){
        cin>>a[i];
        if(i<n) n1[a[i]]++;
        else n2[a[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(a1.size()<k&&n1[i]==2){
            a1.push_back(i);
            a1.push_back(i);
        }
        if(a2.size()<k&&n2[i]==2){
            a2.push_back(i);
            a2.push_back(i);
        }
    }
    for(int i=1;i<=n;++i)
        if(a1.size()<k&&n1[i]==1){
            a1.push_back(i);
            a2.push_back(i);
        }
    for(auto x:a1) cout<<x<<" ";cout<<"\n";
    for(auto x:a2) cout<<x<<" ";cout<<"\n";    
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
