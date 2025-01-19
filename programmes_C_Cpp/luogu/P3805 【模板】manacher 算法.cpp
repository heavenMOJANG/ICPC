#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
const ll N=11000010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,P[N<<1],ans=1;
char S[N<<1];
string s;
void change(){
    n=s.size();
    ll k=0;S[k++]='$';S[k++]='#';
    for(ll i=0;i<n;++i){S[k++]=s[i];S[k++]='#';}
    S[k++]='&';
    n=k;
}
void manacher(){
    ll R=0,C;
    for(ll i=1;i<n;++i){
        if(i<R) P[i]=min(P[(C<<1)-i],P[C]+C-i);
        else P[i]=1;
        while(S[i+P[i]]==S[i-P[i]]) P[i]++;
        if(P[i]+i>R){
            R=P[i]+i;
            C=i;
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    change();
    manacher();
    for(ll i=0;i<n;++i) ans=max(ans,P[i]);
    cout<<ans-1;
    return 0;
}