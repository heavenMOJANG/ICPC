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
ll t;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n+10];
        if(n==1){cout<<"1\n";continue;}
        if(n==2){cout<<"1 2\n";continue;}
        if(n&1){cout<<"-1\n";continue;}
        for(ll i=1;i<=n;++i) a[i]=i;
        for(ll i=1;i<n;i+=2) cout<<a[i+1]<<" "<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}