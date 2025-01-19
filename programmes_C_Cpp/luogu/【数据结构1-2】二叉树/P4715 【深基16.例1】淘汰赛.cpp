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
ll n,a[210],u,v;
queue<ll>q;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=(1<<n);++i) cin>>a[i],q.push(i);
    while(q.size()>1){
        u=q.front();q.pop();
        v=q.front();q.pop();
        if(a[u]>a[v]) q.push(u);
        else q.push(v);
    }
    cout<<(a[u]>a[v]?v:u);
    return 0;
}