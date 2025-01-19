#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,x;
set<ll>s;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>x,s.insert(x);
    cout<<s.size()<<"\n";
    for(set<ll>::iterator it=s.begin();it!=s.end();++it) cout<<*it<<" ";
    return 0;
}