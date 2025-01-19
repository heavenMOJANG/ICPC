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
ll n,tree[1010],s;
void preOrder(ll x){
    cout<<char('a'+x-1);
    if(tree[x<<1]) preOrder(tree[x<<1]);
    if(tree[x<<1|1]) preOrder(tree[x<<1|1]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i){
        char root,l,r;cin>>root>>l>>r;
        ll f=root-'a'+1;
        if(i==1) s=f;
        if(l!='*') tree[f<<1]=l-'a'+1;
        if(r!='*') tree[f<<1|1]=r-'a'+1;
    }
    preOrder(s);
    return 0;
}