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
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
string s,t;
ll cnt;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>t;
    for(ll i=0;i<s.size();++i)
	    for(ll j=1;j<t.size();++j)
	        if(s[i]==t[j]&&s[i+1]==t[j-1]) cnt++;
    cout<<(1<<cnt);
    return 0;
}