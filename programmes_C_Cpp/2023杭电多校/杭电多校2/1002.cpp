#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll T,n,k,f[100010];
string s;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k>>s;
        if(!k){cout<<s<<"\n";continue;}
        if(s=="1"){
            if(k&1){cout<<"0\n";continue;}
            else{cout<<"1\n";continue;}
        }
        for(ll i=0;i<n;++i) f[i]=0;
        ll cnt=0;
        for(ll i=0;i<n;++i){
            if(s[i]=='1') f[i]=1,cnt++;
            else{
                if(!f[i-1]) s[i]='1';
                else{
                    if(!k) break;
                    s[i]='1';
                    k--;
                }
            }
        }
        if(cnt==n){
            if(k==1) s[n-1]='0';
        }
        cout<<s<<"\n";
    }
    return 0;
}
