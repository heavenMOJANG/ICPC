#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<double>f(100010,0.0);
    for(int i=2;i<=100000;++i) f[i]=f[i-1]+log(i);
    int idx=0,n,k;
    while(cin>>n>>k,n||k){
        cout<<"Case "<<++idx<<": ";
        if(n==1){cout<<"0.0000\n";continue;}
        if(n<=2*k+1){cout<<n<<".0000\n";continue;}
        int N=k<<1,p;
        double sum=0.0;
        for(int i=1;i<=n;++i){
            p=max(0ll,i-1-k)+max(0ll,n-k-i);
            if(p<N) continue;
            sum+=exp(f[p]+f[n-N-1]-f[n-1]-f[p-N]);
        }
        cout<<fixed<<setprecision(4)<<(double)(n-sum)<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
