#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n; cin>>n;
    if(n==1){cout<<"1\n";return;}
    cout<<"196";
    for(int i=n-3;i;--i) cout<<"0";
    cout<<"\n";
    for(int i=1; i<n; i+=2){
        int cnt=3;
        cout<<"9";for(int j=1;j<=i/2;++j) cout<<"0",cnt++;
        cout<<"6";for(int j=1;j<=i/2;++j) cout<<"0",cnt++;
        cout<<"1";for(int j=cnt;j<n;++j) cout<<"0";
        cout<<"\n";
    }
 
    for(int i=1; i<n; i+=2){
        int cnt=3;
        cout<<"1";for(int j=1;j<=i/2;++j) cout<<"0",cnt++;
        cout<<"6";for(int j=1;j<=i/2;++j) cout<<"0",cnt++;
        cout<<"9";for(int j=cnt;j<n;++j) cout<<"0";
        cout<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
