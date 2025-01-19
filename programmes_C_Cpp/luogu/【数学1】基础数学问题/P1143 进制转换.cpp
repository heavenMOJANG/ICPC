#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,p,res;
string s;
stack<ll>st;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>s>>m;
    p=s.size();
    for(ll i=0;i<s.size();++i)
        if('A'<=s[i]&&s[i]<='F') res+=(s[i]-'A'+10)*pow(n,p-i-1);
        else res+=(s[i]-'0')*pow(n,p-i-1);
    while(res){
        st.push(res%m);
        res/=m;
    }
    while(!st.empty()){
        ll u=st.top();st.pop();
        if(u>9) cout<<char('A'+u-10);
        else cout<<u;
    }
    return 0;
}