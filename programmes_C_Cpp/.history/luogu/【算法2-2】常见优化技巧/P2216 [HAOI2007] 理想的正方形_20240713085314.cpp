#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1010;
int a,b,n,g[N][N],ymin[N][N],ymax[N][N],xmax[N][N],xmin[N][N],minn=inf;
deque<int>dqmax,dqmin;
void solve(){
    memset(ymin,inf,sizeof(ymin));
    memset(xmin,inf,sizeof(xmin));
    cin>>a>>b>>n;
    for(int i=1;i<=a;++i)
        for(int j=1;j<=b;++j) cin>>g[i][j];
    for(int i=1;i<=a-n+1;++i){
		for(int j=1;j<=b;++j){
			while(dqmax.size()&&dqmax.front()<j-n+1) dqmax.pop_front();
			while(dqmax.size()&&g[i][dqmax.back()]<g[i][j]) dqmax.pop_back();
			dqmax.push_back(j);
			if(j>=n) ymax[i][j-n+1]=max(ymax[i][j-n+1],g[i][dqmax.front()]);
			while(dqmin.size()&&dqmin.front()<j-n+1) dqmin.pop_front();
			while(dqmin.size()&&g[i][dqmin.back()]>g[i][j]) dqmin.pop_back();
			dqmin.push_back(j);
			if(j>=n) ymin[i][j-n+1]=min(ymin[i][j-n+1],g[i][dqmin.front()]);
		}
        dqmax.clear();
        dqmin.clear();
	}
    for(int j=1;j<=b-n+1;++j){
		for(int i=1;i<=a;++i){
			while(dqmax.size()&&dqmax.front()<i-n+1) dqmax.pop_front();
			while(dqmax.size()&&ymax[dqmax.back()][j]<ymax[i][j]) dqmax.pop_back();
			dqmax.push_back(i);
			if(i>=n) xmax[i-n+1][j]=max(xmax[i-n+1][j],ymax[dqmax.front()][j]);
			while(dqmin.size()&&dqmin.front()<i-n+1) dqmin.pop_front();
			while(dqmin.size()&&ymin[dqmin.back()][j]>ymin[i][j]) dqmin.pop_back();
			dqmin.push_back(i);
			if(i>=n) xmin[i-n+1][j]=min(xmin[i-n+1][j],ymin[dqmin.front()][j]);
		}
		dqmax.clear();
        dqmin.clear();
	}
    for(int i=1;i<=a-n+1;++i)
		for(int j=1;j<=b-n+1;++j) minn=min(minn,xmax[i][j]-xmin[i][j]);
    cout<<minn;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
