#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{int b,t;};
void solve(){
    int clk=1,n;
    while(cin>>n&&n){
        cout<<"Case "<<clk<<": ";
        vector<Node>a(n);
        for(int i=0;i<n;++i) cin>>a[i].b>>a[i].t;
        sort(a.begin(),a.end(),[](const Node&x,const Node&y){return x.t>y.t;});
        int res=0,tot=0;
        for(int i=0;i<n;++i){
            tot+=a[i].b;
            res=max(res,tot+a[i].t);
        }
        cout<<res<<"\n";
        clk++;
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
