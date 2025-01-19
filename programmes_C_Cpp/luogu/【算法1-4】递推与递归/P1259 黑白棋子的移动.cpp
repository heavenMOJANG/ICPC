#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
char c[210];
ll n,x;
void writeln(){
    for(ll i=1;i<=2*n+2;++i) cout<<c[i];
    cout<<"\n";
}
void move(ll p){
    swap(c[p],c[x]);
    swap(c[p+1],c[x+1]);
    x=p;
}
void solve(ll p){
    if(p==4){
        ll a[]={4,8,2,7,1}; 
        for(ll i=0;i<5;++i) move(a[i]),writeln();
        return;
    }
    move(p),writeln();
    move(2*p-1),writeln();
    solve(p-1); 
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) c[i]='o',c[i+n]='*';
    x=2*n+1;
    c[x]=c[x+1]='-';
    writeln();
    solve(n);
    return 0;
}