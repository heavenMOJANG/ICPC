#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll T,K,n;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>K>>n;
        cout<<((n==0||(n-(K+1))%(4*K+2)==0)?"Bob\n":"Alice\n");        
    }
    return 0;
}
