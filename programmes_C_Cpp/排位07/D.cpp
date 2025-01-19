#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr double eps=1e-9;
typedef double Matrix[110][110];
int idx;
void solve(){
    int n;
    while(cin>>n,n){
        cout<<"Case #"<<++idx<<":\n";
        int u,v;
        vector<int>d(110,0),pre[110];
        while(cin>>u>>v&&u&&v){
            u--,v--;
            d[u]++;
            pre[v].push_back(u);
        }
        Matrix A;
        for(int i=0;i<n;++i){
            A[i][i]=1;
            for(int j=0;j<pre[i].size();++j) A[i][pre[i][j]]-=1.0/d[pre[i][j]];
            if(!i) A[i][n]=1;
        }
        function<void(Matrix,int)> gauss=[&](Matrix A,int n){
            for(int i=0;i<n;++i){
                int r=i;
                for(int j=i+1;j<n;++j) if(fabs(A[j][i])>fabs(A[r][i])) r=j;
                if(fabs(A[r][i])<eps) continue;
                if(r!=i) for(int j=0;j<=n;++j) swap(A[r][j],A[i][j]);
                for(int k=0;k<n;++k)
                    if(k!=i)
                        for(int j=n;j>=i;--j) A[k][j]-=A[k][i]/A[i][i]*A[i][j];
            }
        };
        gauss(A,n);
        vector<int>inf(110,0);
        for(int i=n-1;i>=0;--i){
            if(fabs(A[i][i]<eps&&fabs(A[i][n]>eps))) inf[i]=1;
            for(int j=i+1;j<n;++j)
                if(fabs(A[i][j])>eps&&inf[j]){inf[i]=1;break;}
        }
        int q;cin>>q;
        while(q--){
            cin>>u,u--;
            if(inf[u]) cout<<"infinity\n";
            else cout<<fixed<<setprecision(3)<<(fabs(A[u][u])<eps?0.0:A[u][n]/A[u][u])<<"\n";
        }
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
