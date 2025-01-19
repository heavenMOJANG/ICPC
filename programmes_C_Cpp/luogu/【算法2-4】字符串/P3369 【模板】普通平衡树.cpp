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
struct node{
    ll lc,rc,val,pri,num,size;
}tr[400010];
ll n,root,cnt;
ll New(ll val){
    tr[++cnt]={0,0,val,rand(),1,1};
    return cnt;
}
void Update(ll p){
    tr[p].size=tr[tr[p].lc].size+tr[tr[p].rc].size+tr[p].num;
}
void zig(ll&p){
    ll q=tr[p].lc;
    tr[p].lc=tr[q].rc;
    tr[q].rc=p;
    tr[q].size=tr[p].size;
    Update(p);
    p=q;
}
void zag(ll&p){
    ll q=tr[p].rc;
    tr[p].rc=tr[q].lc;
    tr[q].lc=p;
    tr[q].size=tr[p].size;
    Update(p);
    p=q;
}
void Insert(ll&p,ll val){
    if(!p){p=New(val);return;}
    tr[p].size++;
    if(val==tr[p].val){
        tr[p].num++;
        return;
    }
    if(val<tr[p].val){
        Insert(tr[p].lc,val);
        if(tr[p].pri<tr[tr[p].lc].pri) zig(p);
    }
    else{
        Insert(tr[p].rc,val);
        if(tr[p].pri<tr[tr[p].rc].pri) zag(p);
    }
}
void Delete(ll&p,ll val){
    if(!p) return;
    tr[p].size--;
    if(val==tr[p].val){
        if(tr[p].num>1){tr[p].num--;return;}
    }
    if(!tr[p].lc||!tr[p].rc) p=tr[p].lc+tr[p].rc;
    else if(tr[tr[p].lc].pri>tr[tr[p].rc].pri) zig(p),Delete(tr[p].rc,val);
    else zag(p),Delete(tr[p].lc,val);
    return;
}
ll GetPre(ll val){
    ll p=root,res=0;
    while(p){
        if(tr[p].val<val){res=tr[p].val;p=tr[p].rc;}
        else p=tr[p].lc;
    }
    return res;
}
ll GetNext(ll val){
    ll p=root,res=0;
    while(p){
        if(tr[p].val>val){res=tr[p].val;p=tr[p].lc;}
        else p=tr[p].rc;
    }
    return res;
}
ll GetRankByVal(ll p,ll val){
    if(!p) return 0;
    if(tr[p].val==val) return tr[tr[p].lc].size+1;
    if(val<tr[p].val) return GetRankByVal(tr[p].lc,val);
    else return GetRankByVal(tr[p].rc,val)+tr[tr[p].lc].size+tr[p].num;
}
ll GetValByRank(ll p,ll rank){
    if(!p) return 0;
    if(tr[tr[p].lc].size>=rank) return GetValByRank(tr[p].lc,rank);
    if(tr[tr[p].lc].size+tr[p].num>=rank) return tr[p].val;
    return GetValByRank(tr[p].rc,rank-tr[tr[p].lc].size-tr[p].num);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,opt,x;i<=n;++i){
        cin>>opt>>x;
        switch(opt){
            case 1:Insert(root,x);break;
            case 2:Delete(root,x);break;
            case 3:cout<<GetRankByVal(root,x)<<"\n";break;
            case 4:cout<<GetValByRank(root,x)<<"\n";break;
            case 5:cout<<GetPre(x)<<"\n";break;
            case 6:cout<<GetNext(x)<<"\n";break;
        }
    }
    return 0;
}