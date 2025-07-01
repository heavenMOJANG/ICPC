#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll T;
string s;
char ch;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        ll sum=0,t=1;
        for(ll i=1;i<s.size();++i){
            if(s[i]==s[i-1]) t++;
            else sum+=t-1,t=1;
        }
        cout<<sum+t-1<<"\n";
    }
    return 0;
}
