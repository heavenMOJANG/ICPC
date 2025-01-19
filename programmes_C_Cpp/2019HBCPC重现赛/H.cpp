#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll T,n,k,x;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        x=n;
        if(k==2) x*=x;
        if(1<=x&&x<=9){cout<<x<<"\n";return 0;}
        while(1){
            ll res=0;
            string s=to_string(x);
            for(ll i=0;i<s.size();++i) res+=s[i]-'0';
            x=res;
            if(1<=res&&res<=9) break;
            else x=res;
        }
        cout<<x<<"\n";
    }
    return 0;
}