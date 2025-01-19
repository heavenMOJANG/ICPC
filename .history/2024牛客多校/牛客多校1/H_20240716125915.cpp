#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=1e5+10;
struct Node{
    string name;
    int passedNum,penaltyTime;
};
map<string,int>mp;
int n,m;
vector<Node>a(N),b(N);
int cmp(Node x,Node y){
    return x.passedNum==y.passedNum?x.penaltyTime<y.penaltyTime:x.passedNum>y.passedNum;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i].name>>a[i].passedNum>>a[i].penaltyTime,mp[a[i].name]++;
    cin>>m;
    for(int i=0;i<m;++i)
        cin>>b[i].name>>b[i].passedNum>>b[i].penaltyTime,mp[b[i].name]++;
    sort(a.begin(),a.begin()+n,cmp);
    sort(b.begin(),b.begin()+m,cmp);
    int rankA=0,rankB=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;++i){
        if(a[i].name=="lzr010506"){rankA=i-cnt1;break;}
        if(mp[a[i].name]==2) cnt1++;
    }
    for(int i=0;i<m;++i){
        if(b[i].name=="lzr010506"){rankB=i-cnt2;break;}
        if(mp[b[i].name]==2) cnt2++;
    }
    cout<<min(rankA,rankB)+1<<"\n";
    return 0;
}