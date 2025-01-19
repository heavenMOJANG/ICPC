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
ll s,m,n;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>m>>n>>s){
        ll flag=1;
        if(n<=s&&m%(s+1)==0) flag=0;
        cout<<(flag?"Alice\n":"Bob\n");
    }
    return 0;
}