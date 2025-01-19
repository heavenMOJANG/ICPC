#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,minn=LLONG_MAX,res,a[5010],b[5010];
char ch;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>ch,a[i]=ch=='F';
    for(ll j=1;j<=n;++j){
        memset(b,0,sizeof(b));
        ll flag=1,tmp=0,cnt=0;
        for(ll i=1;i<=n;++i){
            tmp^=b[i];
            if((a[i]^tmp)==0){
                if(i+j-1>n){flag=0;break;}
                tmp^=1;
                b[i+j]^=1;
                cnt++;
            }
        }
        if(flag) if(cnt<minn) minn=cnt,res=j;
    }
    cout<<res<<" "<<minn;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}