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
struct Node{ll id,num;}a[100010];
ll n,b[100010],res,flag;
set<ll>ans;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].num,a[i].id=i,b[i]=a[i].num;
    sort(b+1,b+1+n);
    for(ll i=1;i<n;++i){
        if(flag) break;
        if(i-1>=30){flag=1;res=b[i];break;}
        ll tmp=min(b[i]*pow(2,i-1),1e9);
        if(tmp>=b[n]){flag=1;res=b[i];break;}
        ll cur=i;
        while(1){
            ll p=upper_bound(b+cur,b+1+n,tmp)-b-1;
            if(p==cur) break;
            if(p-cur>=30){flag=1;res=b[i];break;}
            tmp=min(tmp*pow(2,p-cur),1e9);
            if(tmp>=b[n]){flag=1;res=b[i];break;}
            cur=p;
        }
    }
    for(ll i=1;i<=n;++i) if(a[i].num>=res) ans.insert(a[i].id);
    cout<<ans.size()<<"\n";
    for(auto it=ans.begin();it!=ans.end();++it) cout<<*it<<" ";
    return 0;
}