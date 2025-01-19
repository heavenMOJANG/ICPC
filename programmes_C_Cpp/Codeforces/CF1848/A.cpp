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
ll dx[]={0,0,-1,1};
ll dy[]={-1,1,0,0};
ll T,n,m,k,x,y;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ll flag=0;
        cin>>n>>m>>k>>x>>y;
        for(ll i=1,xi,yi;i<=k;++i){
            cin>>xi>>yi;
            if((abs(x-xi)+abs(y-yi))%2==0) flag=1;
        }
        cout<<(flag?"NO\n":"YES\n");
    }
    return 0;
}