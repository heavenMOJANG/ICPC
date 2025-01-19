#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    string s;
    vector<vector<int>>a(n,vector<int>(m)),b(n,vector<int>(m));
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<m;++j) a[i][j]=s[j]-'0';
    }
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<m;++j) b[i][j]=s[j]-'0';
    }
    for(int i=0;i<n-1;++i)
        for(int j=0;j<m-1;++j)
            if(a[i][j]!=b[i][j]){
                int temp=(b[i][j]-a[i][j]+3)%3,sum=3-temp;
                a[i][j]=(a[i][j]+temp)%3;
                a[i+1][j+1]=(a[i+1][j+1]+temp)%3;
                a[i+1][j]=(a[i+1][j]+sum)%3;
                a[i][j+1]=(a[i][j+1]+sum)%3;
        }
    int flag=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) if(a[i][j]!=b[i][j]) flag=1;
    cout<<(1?"No\n":"Yes\n");
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;
    while(_--) solve();
    return 0;
}