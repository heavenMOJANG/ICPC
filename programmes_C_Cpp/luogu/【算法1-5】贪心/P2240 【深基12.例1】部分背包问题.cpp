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
struct Node{
    double m,v,d;
    bool operator<(const Node&x)const{return d<x.d;}
}a[110];
ll n,t;
double res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(ll i=1;i<=n;++i) cin>>a[i].m>>a[i].v,a[i].d=a[i].v/a[i].m;
    sort(a+1,a+1+n);
    for(ll i=n;i>=1;--i){
        if(t<a[i].m){
            res+=t*a[i].d;
            break;
        }
        else{
            res+=a[i].v;
            t-=a[i].m;
        }
    }
    cout<<fixed<<setprecision(2)<<res;
    return 0;
}