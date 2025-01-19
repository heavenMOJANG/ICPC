#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,m,k;
int check(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
void solve(){
    while(cin>>n>>m>>k){
        vector<vector<int>>a(n+10,vector<int>(m+10));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) cin>>a[i][j];
        int minn=inf;
        for(int mask=0;mask<(1<<m);++mask){
            vector<vector<int>>b=a;
            int cnt=0;
            for(int i=0;i<m;++i)
                if(mask&(1 << i)){
                    b[0][(i+k-1)%m]=(b[0][(i+k-1)%m]+1)%k;
                    b[0][(i+k+1)%m]=(b[0][(i+k+1)%m]+1)%k;
                    b[1][i]=(b[1][i]+1)%k;
                    cnt++;
                }
            for(int i=1;i<n;++i)
                for(int j=0;j<m;++j)
                    while(b[i-1][j]!=0){ 
                        b[i-1][j]=(b[i-1][j]+1)%k;
                        b[i][j]=(b[i][j]+1)%k;
                        if(check(i+1,j)) b[i+1][j]=(b[i+1][j]+1)%k;
                        cnt++;
                    }
            int flag=1;
            for(int i=0;i<m;++i) if(b[n-1][i]!=0){flag=0;break;}
            if(flag) minn=min(minn,cnt);
        }
        if(minn==inf) cout<<"-1\n";
        else cout<<minn<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
