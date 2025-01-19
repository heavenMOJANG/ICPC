#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
string s,t;
ll nxt[1000010];
void getNext(){
    ll len=t.size();
    nxt[0]=0;nxt[1]=0;
    for(ll i=1;i<len;++i){
        ll j=nxt[i];
        while(j&&t[i]!=t[j]) j=nxt[j];
        nxt[i+1]=(t[i]==t[j]?j+1:0);
    }
}
void kmp(){
    ll slen=s.size(),tlen=t.size();
    getNext();
    ll j=0;
    for(ll i=0;i<slen;++i){
        while(j&&s[i]!=t[j]) j=nxt[j];
        if(s[i]==t[j]) j++;
        if(j==tlen) cout<<i+1-tlen+1<<"\n";
    }
}
void solve(){
    cin>>s>>t;
    kmp();
    for(ll i=1;i<=t.size();++i) cout<<nxt[i]<<" ";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
