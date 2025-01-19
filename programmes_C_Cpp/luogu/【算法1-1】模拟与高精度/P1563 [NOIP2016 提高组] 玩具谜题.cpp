#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll to;
    string name;
}doll[100010];
ll n,m,a,s,cnt;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<n;++i) cin>>doll[i].to>>doll[i].name;cin>>doll[0].to>>doll[0].name;
    cnt=1;
    for(ll i=1;i<=m;++i){
        cin>>a>>s;
        if(doll[cnt].to^a) cnt=(cnt+s)%n;
        else cnt=(cnt+n-s)%n;
    }
    cout<<doll[cnt].name;
    return 0;
}