#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Node{ll val,id;}a[1000010];
ll n,l,r,b[1000010];
ll cmp(Node x,Node y){return x.val<y.val;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].val,a[i].id=i;
    sort(a+1,a+1+n,cmp);
    for(ll i=1;i<=n;++i) b[i]=a[i].val;
    l=1,r=n;
    while(l<r){
        ll d=(a[r].val-a[l].val)/2,p=lower_bound(b+1,b+1+n,a[l].val+d)-b;
        if(a[p].val>a[l].val+d) p--;
        if(p-l+1==r-p) r--;
        else{
            if(p-l+1>r-p) r--;
            else l++;
        }
    }
    cout<<a[l].id;
    return 0;
}
