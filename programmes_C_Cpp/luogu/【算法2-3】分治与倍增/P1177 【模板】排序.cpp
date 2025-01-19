#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[100010];
ll Partition(ll a[],ll p,ll r){
    ll i=p,j=r+1,x=a[p];
    while(1){
        while(a[++i]<x&&i<r) ;
        while(a[--j]>x) ;
        if(i>=j) break;
        swap(a[i],a[j]);
    }
    a[p]=a[j];
    a[j]=x;
    return j;
}
ll RandomizedPartition(ll a[],ll p,ll r){
    srand(time(NULL));
    ll i=rand()%(r-p)+p;
    swap(a[i],a[p]);
    return Partition(a,p,r);
}
void RandomizedQuickSort(ll a[],ll p,ll r){
    if(p<r){
        ll q=RandomizedPartition(a,p,r);
        RandomizedQuickSort(a,p,q-1);
        RandomizedQuickSort(a,q+1,r);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    RandomizedQuickSort(a,1,n);
    for(ll i=1;i<=n;++i) cout<<a[i]<<" ";
    return 0;
}