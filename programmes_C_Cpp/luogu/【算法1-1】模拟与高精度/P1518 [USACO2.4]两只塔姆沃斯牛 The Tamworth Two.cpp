#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
char g[15][15];
ll fx,fy,cx,cy,ff,cf,key,res,vis[15][15][15][15][15][15];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i=1;i<=10;++i)
        for(ll j=1;j<=10;++j){
            cin>>g[i][j];
            if(g[i][j]=='F') fx=i,fy=j;
            if(g[i][j]=='C') cx=i,cy=j;
        }
    while(1){
        if(fx==cx&&fy==cy){cout<<res<<"\n";break;}
        if(vis[fx][fy][ff][cx][cy][cf]){return puts("0\n"),0;}
        vis[fx][fy][ff][cx][cy][cf]=1;
        if(fx+dx[ff]<1||fx+dx[ff]>10||fy+dy[ff]<1||fy+dy[ff]>10||g[fx+dx[ff]][fy+dy[ff]]=='*') ff=(ff+1)%4;
        else fx+=dx[ff],fy+=dy[ff];
        if(cx+dx[cf]<1||cx+dx[cf]>10||cy+dy[cf]<1||cy+dy[cf]>10||g[cx+dx[cf]][cy+dy[cf]]=='*') cf=(cf+1)%4;
        else cx+=dx[cf],cy+=dy[cf];
        res++;
    }
    return 0;
}