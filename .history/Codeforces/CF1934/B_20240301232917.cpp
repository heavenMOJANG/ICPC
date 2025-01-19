#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int k=n/15;n%=15;
    switch(n){
        case 0:{cout<<k<<"\n";break;}
        case 1:{cout<<k+1<<"\n";break;}
        case 2:{cout<<k+2<<"\n";break;}
        case 3:{cout<<k+1<<"\n";break;}
        case 4:{cout<<k+2<<"\n";break;}
        case 5:{if(k) cout<<k+1<<"\n";else cout<<"3\n";break;}
        case 6:{cout<<k+1<<"\n";break;}
        case 7:{cout<<k+2<<"\n";break;}
        case 8:{cout<<k+2<<"\n";break;}
        case 9:{cout<<k+2<<"\n";break;}
        case 10:{cout<<k+1<<"\n";break;}
        case 11:{cout<<k+2<<"\n";break;}
        case 12:{cout<<k+2<<"\n";break;}
        case 13:{cout<<k+2<<"\n";break;}
        case 14:{cout<<k+3<<"\n";break;}
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
