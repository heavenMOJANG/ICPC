#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
class Solution{
public:
    ll T,a,b,x;
    void exgcd(ll a,ll b,ll&d,ll&x,ll&y){
        if(!b) d=a,x=1,y=0;
        else exgcd(b,a%b,d,y,x),y-=x*(a/b);
    }
    void main(){
        cin>>T;
        while(T--){
            ll a,b,c,g,x,y;
            cin>>a>>b>>c;
            exgcd(a,b,g,x,y);
            if(c%g){cout<<"-1\n";continue;}
            a/=g,b/=g,c/=g,x*=c,y*=c;
            ll ans=LLONG_MAX;
            auto calc=[&](ll t){
                ll r=x+b*t,s=y-a*t;
                if(r>=0&&s>=0) ans=min(ans,2*(r+s));
                else ans=min(ans,2*(abs(r)+abs(s))-1);
            };
            ll t0=-x/b;
            for(ll t=t0-1;t<=t0+1;++t) calc(t);
            t0=y/a;
            for(ll t=t0-1;t<=t0+1;++t) calc(t);
            cout<<ans<<"\n";
        }
    }
};
int main(int argc,const char**argv){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    solution.main();
    return 0;
}