#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x;cin>>n>>x;
    int a=n+x-2,b=n-x;
    set<int>s;
    for(int i=1;i<=a/i;++i)
        if(a%i==0){
            if(i%2==0&&(i+2)/2>=x) s.insert(i);
            if((a/i)%2==0&&(a/i+2)/2>=x) s.insert(a/i);
        }
    for(int i=1;i<=b/i;++i)
        if(b%i==0){
            if(i%2==0&&(i+2)/2>=x) s.insert(i);
            if((b/i)%2==0&&(b/i+2)/2>=x) s.insert(b/i);
        }
    cout<<s.size()<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
