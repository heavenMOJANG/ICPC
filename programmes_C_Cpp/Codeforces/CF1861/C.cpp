#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
string s;
void solve(){
    cin>>s;
    vector<ll>v{1};
    ll cnt=0,flag=1;
    for(char ch:s)
        switch(ch){
            case '+':{
                ll cur=v.back();
                cnt++;
                if(cur==1&&cnt>=2) cur=-1;
                v.push_back(cur);
            }break;
            case '-':{
                ll cur=v.back();
                cnt--;
                v.pop_back();
                if(cur==1) v.back()=1;
            }break;
            case '0':{
                if(v.back()==1){flag=0;break;}
                if(v.back()==-1) v.back()=0;
            }break;
            case '1':{
                if(v.back()==0){flag=0;break;}
                if(v.back()==-1) v.back()=1;
            }
        }
    cout<<(flag?"YES\n":"NO\n");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
