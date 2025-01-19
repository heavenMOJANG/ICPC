#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
char arr[10];
ll ans,sum[30][10],num;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>arr;
    if(strlen(arr)>6) return cout<<0,0;
    for(ll i=0;i<strlen(arr);++i)
        if(arr[i]<'a'||arr[i]>'z') return cout<<0,0;
    for(ll i=1;i<strlen(arr);++i)
        if(arr[i-1]>=arr[i]) return cout<<0,0;
    for(ll i=1;i<=26;++i) sum[i][1]=1;
    for(ll j=2;j<=6;++j)
        for(ll i=27-j;i;--i) sum[i][j]=sum[i+1][j-1]+sum[i+1][j];
    for(ll j=strlen(arr)-1;j>=0;--j){
        num++;
        for(ll i=1;i<=arr[j]-'a'+1;++i) ans+=sum[i][num];
    }
    cout<<ans<<"\n";
    return 0;
}
