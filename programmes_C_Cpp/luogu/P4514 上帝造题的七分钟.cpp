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
ll n,m,t1[2050][2050],t2[2050][2050],t3[2050][2050],t4[2050][2050];
string s;
ll lowbit(ll x){return x&(-x);}
void update(ll x,ll y,ll d){
    for(ll i=x;i<=n;i+=lowbit(i))
        for(ll j=y;j<=m;j+=lowbit(j)){
            t1[i][j]+=d;t2[i][j]+=x*d;
            t3[i][j]+=y*d;t4[i][j]+=x*y*d;
        }
}
ll sum(ll x,ll y){
    ll res=0;
    for(ll i=x;i>0;i-=lowbit(x))
        for(ll j=y;j>0;j-=lowbit(j))
            res+=(x+1)*(y+1)*t1[i][j]-(y+1)*t2[i][j]-(x+1)*t3[i][j]+t4[i][j];
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>n>>m;
    while(cin>>s){
        ll a,b,c,d,delta;cin>>a>>b>>c>>d;
        if(s=="L"){
            cin>>delta;
            update(a,b,delta);update(c+1,d+1,delta);
            update(a,d+1,-delta);update(c+1,b,-delta);
        }
        else cout<<sum(c,d)+sum(a-1,b-1)-sum(a-1,d)-sum(c,b-1)<<"\n";
    }
    return 0;
}