#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=2e5+10;
int n,x,y;
string s;
vector<pii>pre(N,{0,0});
unordered_map<int,int>ump;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x>>y>>s;
    for(int i=0;i<n;++i){
        pre[i+1]=pre[i];
        switch(s[i]){
            case 'D':pre[i+1].first++;break;
            case 'A':pre[i+1].first--;break;
            case 'W':pre[i+1].second++;break;
            case 'S':pre[i+1].second--;break;
        }
    }
    int ans=(x==0&&y==0);
    ump[0]=1;
    for(int i=1;i<=n;++i){
        int curx=pre[i].first,cury=pre[i].second;
        int tarx=curx-x,tary=cury-y;
        int target=tarx*1000000+tary;
        if(ump.find(target)!=ump.end()) ans+=ump[target];
        int cur=curx*1000000+cury;
        ump[cur]++;
    }
    cout<<ans<<"\n";
    return 0;
}