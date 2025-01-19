#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n;
struct Node{
    string name,status,newStatus;//姓名，职位，修改后职位
    ll point,lv,id;
}a[120];
ll change(string s){
    if(s=="BangZhu") return 0;
    if(s=="FuBangZhu") return 1;
    if(s== "HuFa") return 2;
    if(s=="ZhangLao") return 3;
    if(s=="TangZhu") return 4;
    if(s=="JingYing") return 5;
    return 6;
}
ll cmp1(Node x,Node y){return x.point==y.point?x.id<y.id:x.point>y.point;}
ll cmp2(Node x,Node y){return change(x.newStatus)==change(y.newStatus)?x.lv==y.lv?x.id<y.id:x.lv>y.lv:change(x.newStatus)<change(y.newStatus);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i=1;i<=n;++i) cin>>a[i].name>>a[i].status>>a[i].point>>a[i].lv,a[i].id=i;
    sort(a+4,a+1+n,cmp1);
    for(ll i=1;i<=n;++i)
        if(i == 1) a[i].newStatus="BangZhu";
        else if(2<=i&&i<=3) a[i].newStatus="FuBangZhu";
        else if(4<=i&&i<=5) a[i].newStatus="HuFa";
        else if(6<=i&&i<=9) a[i].newStatus="ZhangLao";
        else if(10<=i&&i<=16) a[i].newStatus="TangZhu";
        else if(17<=i&&i<=41) a[i].newStatus="JingYing";
        else a[i].newStatus="BangZhong";
    sort(a+1,a+1+n,cmp2);
    for(ll i=1;i<=n;++i) cout<<a[i].name<<" "<<a[i].newStatus<<" "<<a[i].lv<<"\n";
    return 0;
}