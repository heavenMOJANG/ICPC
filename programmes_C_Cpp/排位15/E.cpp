#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct segmentTree{int minn;}t[100010<<2];
int n,q,a[100010];
string s;
void pushUp(int p){t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);}
void build(int p,int pl,int pr){
    if(pl==pr){t[p].minn=a[pl];return;}
    int mid=pl+pr>>1;
    build(p<<1,pl,mid);
    build(p<<1|1,mid+1,pr);
    pushUp(p);
}
void update(int p,int pl,int pr,int frm,int lat){
    if(pl==pr){t[p].minn=lat;return;}
    int mid=pl+pr>>1;
    if(frm<=mid) update(p<<1,pl,mid,frm,lat);
    else update(p<<1|1,mid+1,pr,frm,lat);
    pushUp(p);
}
int query(int p,int pl,int pr,int L,int R){
    int res=-1,mid=pl+pr>>1;
    if(L<=pl&&pr<=R) return t[p].minn;
    if(R<=mid) res=query(p<<1,pl,mid,L,R);
    else if(L>mid) res=query(p<<1|1,mid+1,pr,L,R);
    else res=min(query(p<<1,pl,mid,L,R),query(p<<1|1,mid+1,pr,L,R));
    return res;
}
void solve(){
    vector<int>v;
    int tmp=0;
    for(int i=s.find('(')+1;i<s.size();++i){
        if(s[i]==','||s[i]==')') v.push_back(tmp),tmp=0;
        else tmp=tmp*10+s[i]-'0';
    }
    tmp=a[v[0]];
    for(int i=0;i<v.size()-1;++i) update(1,1,n,v[i],a[v[i+1]]),a[v[i]]=a[v[i+1]];
    update(1,1,n,v[v.size()-1],tmp);
    a[v[v.size()-1]]=tmp;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    build(1,1,n);
    while(q--){
        cin>>s;
        if(s[0]=='s') solve();
        else{
            int p=s.find('(')+1,tmp=0,l,r;
            while(s[p]!=','){
                tmp=tmp*10+s[p]-'0';
                p++;
            }
            l=tmp,tmp=0;
            p=s.find(',')+1;
            while(s[p]!=')'){
                tmp=tmp*10+s[p]-'0';
                p++;
            }
            r=tmp;
            cout<<query(1,1,n,l,r)<<"\n";
        }
    }
    return 0;
}
