#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ull m,n;
__int128 f[1010];
inline void writeln(__int128 n){
    if(n<0){
        putchar('-');
        n*=-1;
    }
    if(n>9) writeln(n/10);
    putchar(n % 10 + '0');
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    f[1]=f[2]=1;
    for(ll i=3;i<=n-m+1;++i) f[i]=f[i-1]+f[i-2];
    writeln(f[n-m+1]);
    return 0;
}