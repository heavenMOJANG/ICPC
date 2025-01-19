#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
int a[200010],l[200010],r[200010],v[200010],s1[200010],s2[200010];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    int ans=0,cnt=0,ma1=0,ma2=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    for(int i=1;i<=m;++i){
        cin>>l[i]>>r[i];
        v[l[i]]++,v[r[i]+1]--;
        a[i]=i;
    }
    int s=0;
    for(int i=1;i<=n;++i){
        s+=v[i];
        if(!s) cnt++;
        if(s==1) s1[i]=1;
        if(s==2) s2[i]=1;
    }
    for(int i=1;i<=n;++i) s1[i]+=s1[i-1],s2[i]+=s2[i-1];
    for(int i=1;i<=m;i++) {
        s=s1[r[i]]-s1[l[i]-1];
        if(s>ma1) ma2=ma1,ma1=s;
        else if (s>ma2) ma2=s;
    }
    ans=max(ans,ma1+ma2);
    auto cmp=[&](int x,int y){return l[x]<l[y];};
    sort(a+1,a+1+m,cmp);
    int now=1;
    for(int i=1;i<=n;++i){
        while(!q.empty()&&i>q.top().first) q.pop();
        while(now<=m&&l[a[now]]==i) q.push({r[a[now]],a[now]}),now++;
        if(s2[i]-s2[i-1]==0) continue;
        int num1,num2;
        num1=q.top().second; q.pop();
        num2=q.top().second;
        q.push({r[num1],num1});
        int ll=min(l[num1],l[num2]),rr=max(r[num1],r[num2]),L=max(l[num1],l[num2]),R=min(r[num1],r[num2]);
        int sum=s1[rr]-s1[ll-1]+s2[R]-s2[L-1];
        ans=max(ans,sum);
    }
    cout<<ans+cnt<<"\n";
    for(int i=1;i<=n+1;++i) v[i]=s1[i]=s2[i]=0;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
