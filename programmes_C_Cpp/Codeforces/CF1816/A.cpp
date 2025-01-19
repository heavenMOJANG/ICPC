#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a,b;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(__gcd(a,b)==1){cout<<1<<"\n"<<a<<" "<<b<<"\n";continue;}
        else{
            cout<<"2\n";
            if(a>b){
                ll x=a/2,y=x+1;
                while(1){if(__gcd(x,y)==1&&__gcd(abs(a-x),abs(b-y))==1){cout<<x<<" "<<y<<"\n";break;}y++;}
            }
            else{
                ll y=b/2,x=y+1;
                while(1){if(__gcd(x,y)==1&&__gcd(abs(a-x),abs(b-y))==1){cout<<x<<" "<<y<<"\n";break;}x++;}
            }
            cout<<a<<" "<<b<<"\n";
        }
    }
    return 0;
}