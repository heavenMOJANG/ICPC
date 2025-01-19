#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=9901;
class Solution{
private:
    ll a,b,res=1;
    vector<ll>p,k;
public:
    ll qpow(ll x,ll p){
        ll res=1;
        while(p){
            if(p&1) res=x*res%mod;
            x=x*x%mod;
            p>>=1;
        }
        return res;
    }
    void main(){
        cin>>a>>b;
        if(!a){cout<<"0";return;}
        if(!b){cout<<"1";return;}
        ll tmp=a;
        for(ll i=2;i*i<=a;++i)
            if(tmp%i==0){
                p.push_back(i);
                k.push_back(0);
                while(tmp%i==0){
                    tmp/=i;
                    k.back()++;
                }
            }
        if(tmp>1){
            p.push_back(tmp);
            k.push_back(1);
        }
        for(ll i=0;i<k.size();++i) k[i]*=b;
        for(ll i=0;i<k.size();++i)
            if(p[i]%mod==1) res=res*(k[i]+1)%mod;
            else res=((res*(qpow(p[i],k[i]+1)-1))%mod+mod)*qpow(p[i]-1,mod-2)%mod;
        cout<<res;
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}
