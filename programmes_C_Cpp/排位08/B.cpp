#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,idx=0;
    while(cin>>n&&n){
        if(n==1){cout<<"Case "<<++idx<<": 2\n";continue;}
        int sum=0,cnt=0;
        for(int i=2;i*i<=n;++i)
            if(n%i==0){
                int tmp=1;
                while(n%i==0) n/=i,tmp*=i;
                sum+=tmp;
                cnt++;
            }
        if(n>1) sum+=n,cnt++;
        cout<<"Case "<<++idx<<": "<<sum+(cnt>1?0:1)<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
