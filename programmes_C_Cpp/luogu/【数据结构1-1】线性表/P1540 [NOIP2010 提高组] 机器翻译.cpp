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
queue<ll>q;
map<ll,ll>mp;
ll m,n,res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    while(n--){
        ll x;cin>>x;
        if(mp[x]) continue;
        if(q.size()==m) mp[q.front()]=0,q.pop();
        mp[x]=1,q.push(x),res++;
    }
    cout<<res;
    return 0;
}