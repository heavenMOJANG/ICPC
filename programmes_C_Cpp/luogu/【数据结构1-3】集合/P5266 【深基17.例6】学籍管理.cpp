#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n;
string s;
map<string,ll>mp;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,op;i<=n;++i){
        cin>>op;
        switch(op){
            case 1:{
                cin>>s;
                ll sc;cin>>sc;
                mp[s]=sc;
                cout<<"OK\n";
            }break;
            case 2:{
                cin>>s;
                if(mp.find(s)!=mp.end()){
                    cout<<mp[s]<<"\n";
                }
                else cout<<"Not found\n";
            }break;
            case 3:{
                cin>>s;
                if(mp.find(s)!=mp.end()){
                    mp.erase(s);
                    cout<<"Deleted successfully\n";
                }
                else cout<<"Not found\n";
            }break;
            case 4:{
                cout<<mp.size()<<"\n";
            }break;
        }
    }
    return 0;
}