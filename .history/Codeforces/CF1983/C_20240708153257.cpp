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
    int rL=1,lR=n;
    while(preA[rL]<border&&rL<=n) rL++;
    while(sufC[lR]<border&&lR>=1) lR--;
    if(rL<=lR&&preB[lR]-preB[rL-1]>=border){cout<<"1 "<<rL-1<<" "<<rL<<" "<<lR<<" "<<lR+1<<" n\n";return;}
    //Situation 2 ACB
    while(preA[rL]<border&&rL<=n) rL++;
    while(sufB[lR]<border&&lR>=1) lR--;
    if(rL<=lR&&preC[lR]-preC[rL-1]>=border){cout<<"1 "<<rL-1<<" "<<lR+1<<" n "<<rL<<" "<<lR<<"\n";return;}
    //Situation 3 BAC
    while(preB[rL]<border&&rL<=n) rL++;
    while(sufC[lR]<border&&lR>=1) lR--;
    if(rL<=lR&&preA[lR]-preA[rL-1]>=border){cout<<"1 "<<rL-1<<" "<<rL<<" "<<lR<<" "<<lR+1<<" n\n";return;}
    //Situation 4 BCA
    //Situation 5 CAB
    //Situation 6 CBA
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}