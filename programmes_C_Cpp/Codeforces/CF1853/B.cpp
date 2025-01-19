#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,k,f1[1000010],f2[1000010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f1[3]=1,f1[4]=1;
	f2[3]=1,f2[4]=2;
	for(ll i=5;i<=210000;++i){
		f1[i]=f1[i-1]+f1[i-2];
		f2[i]=f2[i-1]+f2[i-2];
	}
    cin>>_;
    while(_--){
        cin>>n>>k;
        if(k>30){cout<<"0\n";continue;}
	    ll cnt=0;
	    for(ll i=n/(f1[k]+f2[k]);i>=0;--i){
		    ll j=(n-f1[k]*i)/f2[k];
	        if(f1[k]*i+f2[k]*j==n) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
