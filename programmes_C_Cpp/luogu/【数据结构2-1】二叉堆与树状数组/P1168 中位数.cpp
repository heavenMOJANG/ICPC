#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
priority_queue<ll>l;
priority_queue<ll,vector<ll>,greater<ll>>r;
ll n;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,x;i<=n;++i){
        cin>>x;
        l.push(x);r.push(x);
        if(i%2==0) continue;
        while(l.top()!=r.top()){
            ll u=l.top();l.pop();
            ll v=r.top();r.pop();
            l.push(v);r.push(u);
        }
        cout<<l.top()<<"\n";
    }
    return 0;
}