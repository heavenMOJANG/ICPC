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
    int flag=1;
    set<int>s;
    for(int i=0;i<n;++i){
        cin>>a[i];
        s.insert(a[i]);
        if(a[i]!=a[0]) flag=0;
    }
    if(n==1||flag){cout<<"Alice\n";return;}
    int t=1,n1=s.size();
    while(*s.begin()==t){
        s.erase(t);
        t++;
    }
    int n2=s.size();
    if((n1-n2)&1) cout<<(n2&1?"Bob\n":"Alice\n");
    else cout<<(n2&1?"Alice\n":"Bob\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}