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
struct Node{ll x,y;}ap[5010];
ll n,s,a,b,idx,cnt;
ll cmp(Node x,Node y){return x.y<y.y;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s>>a>>b;
    for(ll i=1;i<=n;++i){
        ll x,y;cin>>x>>y;
        if(x<=a+b) ap[++idx]={x,y};
    }
    sort(ap+1,ap+1+idx,cmp);
    for(ll i=1;i<=idx;++i){
        if(s>=ap[i].y) s-=ap[i].y,cnt++;
        else break;
    }
    cout<<cnt;
    return 0;
}