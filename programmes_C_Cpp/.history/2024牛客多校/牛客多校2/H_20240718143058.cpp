#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
int n,x,y;
string s;
map<pii,int>mp;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x>>y>>s;
    if(x==0&&y==0){cout<<n*(n+1)/2<<"\n";return 0;}
    int cx=0,cy=0;
    mp[{0,0}]=1;
    int ans=0;
    for(char c:s){
        switch(c){
            case 'D':cx++;break;
            case 'A':cx--;break;
            case 'W':cx++;break;
            case 'S':cy--;break;
        }
        int tx=cx-x,ty=cy-y;
        if(cx==tx&&cy==ty||ump.find({tx,ty})!=ump.end()) ans+=ump[{cx,cy}];
        ump[{cx,cy}]++; 
    }
    cout<<ans<<"\n";
    return 0;
}