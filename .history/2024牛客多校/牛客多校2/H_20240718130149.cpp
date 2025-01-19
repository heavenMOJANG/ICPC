#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=2e5+10;
struct pair_hash {
    template <class T1,class T2>
    size_t operator()(const pair<T1,T2>&p)const{
        auto hash1=hash<T1>{}(p.first);
        auto hash2=hash<T2>{}(p.second);
        return hash1^hash2;
    }
};
int n,x,y;
string s;
unordered_map<pii,int,pair_hash>ump;
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x>>y>>s;
    int cx=0,cy=0;
    ump[{0,0}]=1;
    int ans=0;
    for(int i=0;i<n;++i){
        switch(s[i]){
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