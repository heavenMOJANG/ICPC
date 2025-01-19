#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;  cin>>n>>k;
    int i=1,l=1,r=n,bl=1;  
    vector<int>ans(n+1);
    while(i<=k){
        int j=i;
        if(bl){
            while(j<=n) ans[j]=l++,j+=k;
            bl^=1;
        }
        else{
            while(j<=n) ans[j]=r--,j+=k;
            bl^=1;
        }
        i++;
    }
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout << "\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
