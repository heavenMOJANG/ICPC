#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
vector<int> manacher(string s){
    string t="#";
    for(auto c:s){t+=c;t+='#';}
    int n=t.size();
    vector<int>r(n);
    for(int i=0,j=0;i<n;++i){
        if(2*j-i>=0&&j+r[j]>i) r[i]=min(r[2*j-i],j+r[j]-i);
        while(i-r[i]>=0&&i+r[i]<n&&t[i-r[i]]==t[i+r[i]]){
            r[i]+=1;
            if(i+r[i]>j+r[j]) j=i;
        }
    }
    return r;
}
void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<int>f1(n),f2(n);
    for(int i=n-1;i>=0;--i){
        if(i+1<n&&s[i+1]==s[i]) f1[i]=f1[i+1];
        else f1[i]=i+1;
        if(i+2<n&&s[i+2]==s[i]) f2[i]=f2[i+2];
        else f2[i]=i+2;
    }
    auto rad=manacher(s);
    while(m--){
        int ans=0,l,r;
        cin>>l>>r;
        l--;
        int len=r-l;
        if(f1[l]<r){
            int temp=((len-1)-(len-1)%2);
            if(temp>=2) ans=ans+(2+temp)*((temp-2)/2+1)/2;
        }
        if(f2[l]<r||f2[l+1]<r){
            int temp=((len-1)-len%2);
            if(temp>=3)ans=ans+(3+temp)*((temp-3)/2+1)/2;
        }
        if(rad[l+r]<len) ans=ans+len;
        cout<<ans<<"\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
