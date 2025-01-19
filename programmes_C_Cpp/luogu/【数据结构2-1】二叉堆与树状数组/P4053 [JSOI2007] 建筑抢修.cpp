#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
priority_queue<ll,vector<ll>,less<ll>>q;
struct Node{ll c,d;}a[200010];
ll n,sum;
ll cmp(Node x,Node y){return x.d==y.d?x.c<y.c:x.d<y.d;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].c>>a[i].d;
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=n;++i){
        sum+=a[i].c;
        q.push(a[i].c);
        if(sum>a[i].d) sum-=q.top(),q.pop();
    }
    cout<<q.size()<<"\n";
    return 0;
}