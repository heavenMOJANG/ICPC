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
ll n,a[110],first,cnt;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=n;i>=0;--i) cin>>a[i];
    for(ll i=n;i>=0;--i){
        if(a[i]==0){
            if(cnt) continue;
            else if(i==0) cout<<"0";
        }
        if(a[i]>0){
            if(first) cout<<"+";
            if(a[i]==1){
                if(i==0) cout<<1;
            }
            else cout<<a[i];
        }
        if(a[i]<0){
            if(a[i]==-1){
                if(i==0) cout<<-1;
                else cout<<"-";
            }
            else cout<<a[i];
        }
        switch(i){
            case 0:break;
            case 1:cout<<"x";break;
            default:cout<<"x^"<<i;
        }
        if(!first) first=1;
        cnt++;
    }
    return 0;
}