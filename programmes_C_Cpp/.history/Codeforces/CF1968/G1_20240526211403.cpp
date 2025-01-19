#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;
    string s;cin>>n>>s>>k;
    int l=0,r=n/k;
    function<bool(int)> check=[&](int x){
        if(!x) return 1;
        string t=s.substr(0,x);
        vector<int>next(x+1,0);
        next[0]=-1;
        for(int i=1,j=-1;i<x;++i){
            while(j>=0&&t[j+1]!=t[i]) j=next[j];
            if(t[j+1]==t[i]) j++;
            next[i]=j;
        }
        int tmp=0;
        for(int i=0,j=-1;i<n;++i){
            while(j!=-1&&s[i]!=t[j+1]) j=next[j];
            if(s[i]==t[j+1]) j++;
            if(j==x-1) tmp++,j=-1;
        }
        return tmp>=k;
    };
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}