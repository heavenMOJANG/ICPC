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
ll n,q;
map<PLL,ll>mp;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    while(q--){
        ll op,i,j,k;cin>>op>>i>>j;
        switch(op){
            case 1:cin>>k;mp[{i,j}]=k;break;
            case 2:cout<<mp[{i,j}]<<"\n";break;
        }
    }
    return 0;
}