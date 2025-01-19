#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,q,a[200010],dp[200010][20],le[200010],ri[200010],num[200010],cnt[200010];
void init(int n,int cnt[]){
    for(int i=1;i<=n;++i) dp[i][0]=cnt[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=1;i+(1<<j)-1<=n;++i) dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int L,int R){
    int k=0;
    while(1<<(k+1)<=R-L+1) k++;
    return max(dp[L][k],dp[R+1-(1<<k)][k]);
}
void solve(){
    while(cin>>n,n){
        memset(cnt,0,sizeof cnt);
        cin>>q>>a[1];
        int tmp=1;
        le[tmp]=ri[tmp]=cnt[tmp]=1;
        num[1]=tmp;
        for(int i=2;i<=n;++i){
            cin>>a[i];
            if(a[i]==a[i-1]) num[i]=tmp,ri[tmp]=i,cnt[tmp]++;
            else num[i]=++tmp,le[tmp]=ri[tmp]=i,cnt[tmp]=1;
        }
        init(n,cnt);
        while(q--){
            int l,r;cin>>l>>r;
            int ll=num[l],rr=num[r];
            if(ll==rr) cout<<r-l+1<<"\n";
            else{
                int tmp1=ri[num[l]]-l+1,tmp2=r-le[num[r]]+1,tmp3=0;
                if(rr-ll>1) tmp3=query(ll+1,rr-1);
                int maxn=max({tmp1,tmp2,tmp3});
                cout<<maxn<<"\n";
            }
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
