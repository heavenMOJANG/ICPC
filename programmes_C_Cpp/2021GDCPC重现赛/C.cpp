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
ll n,q,h[10];
string s;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q>>s;
    for(ll i=0;i<s.size();++i) h[s[i]-'0']++;
    while(q--){
        ll k,maxn=0;cin>>k;
        for(ll i=0;i<=9;++i) if(h[i]>=k) maxn=max(maxn,h[i]);
        cout<<maxn<<"\n";
    }
    return 0;
}