#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,res;
priority_queue<ll,vector<ll>,greater<ll>>q;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,x;i<=n;++i) cin>>x,q.push(x);
    while(q.size()>=2){
        ll x=q.top();q.pop();
        ll y=q.top();q.pop();
        q.push(x+y);
        res+=x+y;
    }
    cout<<res;
    return 0;
}