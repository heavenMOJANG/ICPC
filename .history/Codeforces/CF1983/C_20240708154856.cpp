#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),b(n+1),c(n+1);
    vector<int>preA(n+1,0),preB(n+1,0),preC(n+1,0);
    vector<int>sufA(n+2,0),sufB(n+2,0),sufC(n+2,0);
    for(int i=1;i<=n;++i) cin>>a[i],preA[i]=preA[i-1]+a[i];
    for(int i=1;i<=n;++i) cin>>b[i],preB[i]=preB[i-1]+b[i];
    for(int i=1;i<=n;++i) cin>>c[i],preC[i]=preC[i-1]+c[i];
    for(int i=n;i>=1;--i){
        sufA[i]=sufA[i+1]+a[i];
        sufB[i]=sufB[i+1]+b[i];
        sufC[i]=sufC[i+1]+c[i];
    }
    int border=(preA[n]+2)/3;
    //Situation 1 ABC
    int L=1,R=n;
    while(preA[L-1]<border&&L<=n) L++;
    while(sufC[R+1]<border&&R>=1) R--;
    if(L<=R&&preB[R]-preB[L-1]>=border){cout<<"1 "<<L-1<<" "<<L<<" "<<R<<" "<<R+1<<" "<<n<<"\n";return;}
    //Situation 2 ACB
    L=1,R=n;
    while(preA[L-1]<border&&L<=n) L++;
    while(sufB[R+1]<border&&R>=1) R--;
    if(L<=R&&preC[R]-preC[L-1]>=border){cout<<"1 "<<L-1<<" "<<R+1<<" "<<n<<" "<<L<<" "<<R<<"\n";return;}
    //Situation 3 BAC
    L=1,R=n;
    while(preB[L-1]<border&&L<=n) L++;
    while(sufC[R+1]<border&&R>=1) R--;
    if(L<=R&&preA[R]-preA[L-1]>=border){cout<<L<<" "<<R<<" 1 "<<L-1<<" "<<R+1<<" "<<n<<"\n";return;}
    //Situation 4 BCA
    L=1,R=n;
    while(preB[L-1]<border&&L<=n) L++;
    while(sufA[R+1]<border&&R>=1) R--;
    if(L<=R&&preC[R]-preC[L-1]>=border){cout<<R+1<<" "<<n<<" 1 "<<L-1<<" "<<L<<" "<<R<<"\n";return;}
    //Situation 5 CAB
    L=1,R=n;
    while(preC[L-1]<border&&L<=n) L++;
    while(sufB[R+1]<border&&R>=1) R--;
    if(L<=R&&preA[R]-preA[L-1]>=border){cout<<L<<" "<<R<<" "<<R+1<<" "<<n<<" 1"<<L-1<<"\n";return;}
    //Situation 6 CBA
    L=1,R=n;
    while(preC[L-1]<border&&L<=n) L++;
    while(sufA[R+1]<border&&R>=1) R--;
    if(L<=R&&preB[R]-preB[L-1]>=border){cout<<R+1<<" "<<n<<" "<<L<<" "<<R<<" 1 "<<L-1<<"\n";return;}
    cout<<"-1\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}