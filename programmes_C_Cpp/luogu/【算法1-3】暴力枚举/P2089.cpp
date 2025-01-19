#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll a=1;a<=3;++a)
        for(ll b=1;b<=3;++b)
            for(ll c=1;c<=3;++c)
                for(ll d=1;d<=3;++d)
                    for(ll e=1;e<=3;++e)
                        for(ll f=1;f<=3;++f)
                            for(ll g=1;g<=3;++g)
                                for(ll h=1;h<=3;++h)
                                    for(ll i=1;i<=3;++i)
                                        for(ll j=1;j<=3;++j)
                                            if(a+b+c+d+e+f+g+h+i+j==n) cnt++;
    cout<<cnt<<"\n";
    for(ll a=1;a<=3;++a)
        for(ll b=1;b<=3;++b)
            for(ll c=1;c<=3;++c)
                for(ll d=1;d<=3;++d)
                    for(ll e=1;e<=3;++e)
                        for(ll f=1;f<=3;++f)
                            for(ll g=1;g<=3;++g)
                                for(ll h=1;h<=3;++h)
                                    for(ll i=1;i<=3;++i)
                                        for(ll j=1;j<=3;++j)
                                            if(a+b+c+d+e+f+g+h+i+j==n) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<" \n";
    return 0;
}