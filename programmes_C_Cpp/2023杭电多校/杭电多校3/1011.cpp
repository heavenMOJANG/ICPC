#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,z,h[26],N,cnt;
char g[55][55];
class Solution{
public:
    void main(){
        fill(h,h+26,0);
        cnt=0;
        cin>>n>>z;
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) cin>>g[i][j],h[g[i][j]-'a']=1;
        if(n*z%100){cout<<"error\n";return;}
        N=n*z/100;
        for(ll i=0;i<26;++i) cnt+=h[i]; 
        if(N%n){
            for(ll i=1;i<=n;++i)
                for(ll j=1;j<=n;++j){
                    ll p=N*j%n;
                    if(p)
                        if(g[i][j]!=g[i][j+1]){
                            cout<<"error\n";
                            return;
                        }
                }
            for(ll i=1;i<=N;++i){
                for(ll j=1;j<=N;++j){
                    cout<<g[(ll)ceil(1.0*i*n/N)][(ll)ceil(1.0*j*n/N)];
                }
                cout<<"\n";
            }
        }
        else{
            for(ll i=1;i<=n;++i){
                for(ll k=1;k<=N/n;++k){
                    for(ll j=1;j<=n;++j){
                        for(ll l=1;l<=N/n;++l) cout<<g[i][j];
                    }
                    cout<<"\n";
                }
            }
        }
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    cin>>_;
    while(_--){
        solution.main();
    }
    return 0;
}
