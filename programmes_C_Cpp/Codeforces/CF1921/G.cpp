#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
string s[100010];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<vector<int>>row(n+1,vector<int>(m+1,0)),col(m+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i){
        cin>>s[i];
        for(int j=1;j<=m;++j){
            int a=(s[i][j-1]=='#');
            row[i][j]=row[i][j-1]+a;
        }
    }
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j){
            int a=(s[j][i-1] == '#');
            col[i][j]=col[i][j-1]+a;
        }
    int ans=0;
    if(n<m){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int sum=0;
                for(int h=i,len=k;h>=i-k&&h>=1;h--,len--) sum+=row[h][min(m,j+len)]-row[h][j-1];
                ans=max(ans,sum);
                sum=0;
                for(int h=i,len=k;h<=i+k&&h<=n;h++,len--) sum+=row[h][min(m,j+len)]-row[h][j-1];
                ans=max(ans,sum);
                sum=0;
                for(int h=i,len=k+1;h<=i+k&&h<=n;h++,len--) sum+=row[h][j]-row[h][max(0ll,j-len)];
                ans=max(ans,sum);
                sum=0;
                for(int h=i,len=k+1;h>=i-k&&h>=1;h--,len--) sum+=row[h][j]-row[h][max(0ll,j-len)];
                ans=max(ans,sum);
            }
        }
    }
    else{
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int sum=0;
                for(int w=j,len=k+1;w<=j+k&&w<=m;w++,len--) sum+=col[w][i]-col[w][max(0ll,i-len)];
                ans=max(ans,sum);
                sum=0;
                for(int w=j,len=k;w<=j+k&&w<=m;w++,len--) sum+=col[w][min(n,i+len)]-col[w][i-1];
                ans=max(ans,sum);
                sum=0;
                for(int w=j,len=k;w>=j-k&&w>=1;w--,len--) sum+=col[w][min(n,i+len)]-col[w][i-1];
                ans=max(ans,sum);
                sum=0;
                for(int w=j,len=k+1;w>=j-k&&w>=1;w--,len--) sum+=col[w][i]-col[w][max(0ll,i-len)];
                ans=max(ans,sum);
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--)solve();
    return 0;
}
