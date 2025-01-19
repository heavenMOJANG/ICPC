#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll m,n,x,y,tim[100]={0,0,1,2,5},mark[100][100];
char g[5000][10000];
void dfs(ll p,ll q,ll lvl,ll lyr,ll left,ll num){
    if(lyr==0){
        g[p][q]='o';
        if(mark[lvl][num]){
            g[p][q]=' ';
            if(left)
                for(ll i=p-1,j=q+1;g[i][j]!='o';--i,++j) g[i][j]=' ';
			else
                for(ll i=p-1,j=q-1;g[i][j]!='o';--i,--j) g[i][j]=' ';
            return;
        }
        if(lvl==m) return;
        dfs(p+1,q-1,lvl,lyr+1,1,num*2-1);
        dfs(p+1,q+1,lvl,lyr+1,0,num*2);
    }
	else{
        g[p][q]=left?'/':'\\';
        if(lyr==tim[m+1-lvl]){
            if(left) dfs(p+1,q-1,lvl+1,0,1,num);
            else dfs(p+1,q+1,lvl+1,0,0,num);
        }
		else{
            if(left) dfs(p+1,q-1,lvl,lyr+1,1,num);
            else dfs(p+1,q+1,lvl,lyr+1,0,num);
        }
    }
}
void solve(){
	memset(g,' ',sizeof(g));
    for(ll i=3;i<100;++i) tim[i]=3*pow(2,i-3)-1;
    cin>>m>>n;
    if(m==1) x=1,y=1;
	else x=6*pow(2,m-2)-1,y=3*pow(2,m-2);
    for(ll i=0,t1,t2;i<n;++i) cin>>t1>>t2,mark[t1][t2]=1;
    dfs(1,x/2+1,1,0,0,1);
    for(ll i=1;i<=y;++i){
        for(ll j=1;j<=x;++j) cout<<g[i][j];
        cout<<"\n";
    }
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	solve();
    return 0;
}