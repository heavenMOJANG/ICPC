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
string s;
ll k,r;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>k;
    while(k--){
        ll p=0,flag=0;
        while(p!=s.size()-1){
            if(s[p]>s[p+1]){
                s.erase(p,1);
                flag=1;
                break;
            }
            p++;
        }
        if(!flag) s.erase(p,1);
    }
    for(ll i=0;i<s.size();++i) if(s[i]!='0'){r=i;break;}
    for(ll i=r;i<s.size();++i) cout<<s[i];
    return 0;
}