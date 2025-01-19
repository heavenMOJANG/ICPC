#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int l,r;
    for(int i=0;i<n;++i) if(a[i]){l=i;break;}
    for(int i=n-1;i>=0;--i) if(a[i]){r=i;break;}
    int sum=0;
    while(1){
        while(a[l]&&l<r) l++;
        if(!a[l]){
            l++,sum++;
            while(!a[r]&&l<r) r--;
        }
        else break;
    } 
    cout<<sum<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}